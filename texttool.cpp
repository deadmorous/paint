#include "texttool.h"
#include "canvas.h"
#include "texttoolsetupwidget.h"
#include "scopedinc.h"

#include <QAction>
#include <QIcon>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QCoreApplication>
#include <QTimerEvent>

DECL_PAINT_TOOL_REGISTRATOR(TextTool)

static QSizeF textSize(QPainter& painter, const QString& text)
{
    int BigSize = 1000;
    return painter.boundingRect(QRectF(0, 0, BigSize, BigSize), text).size();
}

TextTool::TextTool(QObject *parent) :
    PaintTool(parent),
    m_eventFileterRecursionDepth(0),
    m_hasLastPos(false),
    m_cursorVisible(false),
    m_timerId(-1)
{
    m_toolAction = new QAction(QIcon(":/pix/text.png"), tr("Brush"), this);
    m_toolAction->setShortcut(Qt::Key_F2);
    m_toolSetupWidget = new TextToolSetupWidget;
    m_toolSetupWidget->hide();
}

QAction *TextTool::toolAction()
{
    return m_toolAction;
}

QWidget *TextTool::toolSetupWidget()
{
    return m_toolSetupWidget;
}

void TextTool::onActivate()
{
    m_hasLastPos = false;
    Q_ASSERT(m_timerId == -1);
    m_timerId = startTimer(500);
    Q_ASSERT(m_timerId != -1);
    canvas()->update();
}

void TextTool::onDeactivate()
{
    Q_ASSERT(m_timerId != -1);
    killTimer(m_timerId);
    m_timerId = -1;
}

bool TextTool::eventFilter(QObject *watched, QEvent *event)
{
    if (m_eventFileterRecursionDepth > 0)
        return false;
    ScopedInc inc(m_eventFileterRecursionDepth);
    if (watched != canvas())
        return false;
    switch(event->type()) {
    case QEvent::MouseButtonPress: {
        auto mouseEvent = static_cast<QMouseEvent*>(event);
        m_lastPos = mouseEvent->pos();
        m_hasLastPos = true;
        m_cursorVisible = false;
        break;
    }
    case QEvent::KeyPress: {
        if (!m_hasLastPos)
            break;
        auto keyEvent = static_cast<QKeyEvent*>(event);
        CanvasPixmap cpix(canvas());
        QPainter p(cpix);
        p.setPen(m_toolSetupWidget->textColor());
        p.setFont(m_toolSetupWidget->textFont());
        QString text = keyEvent->text();
        p.drawText(m_lastPos, text);
        m_lastPos.rx() += textSize(p, text).width();
        break;
    }
    case QEvent::Paint: {
        qApp->notify(canvas(), event);
        QPainter p(canvas());
        if (m_hasLastPos && m_cursorVisible && canvas()->hasFocus()) {
            p.setFont(m_toolSetupWidget->textFont());
            int h = textSize(p, "X").height();
            p.fillRect(m_lastPos.x(), m_lastPos.y()-h, 3, h, QColor::fromRgba(0x88000000));
        }
        return true;
    }
    default:
        break;
    }
    return false;
}

void TextTool::timerEvent(QTimerEvent *event)
{
    if (event->timerId() != m_timerId)
        return;
    if (!isActive())
        return;
    if (!m_hasLastPos)
        return;
    m_cursorVisible = !m_cursorVisible;
    canvas()->update();
}
