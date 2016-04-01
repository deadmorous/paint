#include "fontpicker.h"
#include "fontfamilymodel.h"
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QStandardItemModel>

FontPicker::FontPicker(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);
    m_cbFamilyList = new QComboBox;
    m_cbStyleList = new QComboBox;
    m_cbStyleList->setModel(m_styleModel = new QStandardItemModel(this));
    m_cbSizeList = new QComboBox;
    auto sizeModel = new QStandardItemModel;
    foreach (int size, QFontDatabase::standardSizes())
        sizeModel->appendRow(new QStandardItem(QString::number(size)));
    m_cbSizeList->setModel(sizeModel);
    m_cbSizeList->setCurrentText("12");

    QLabel *familyLabel = new QLabel("F&amily");
    familyLabel->setBuddy(m_cbFamilyList);

    QLabel *styleLabel = new QLabel("&Style");
    styleLabel->setBuddy(m_cbStyleList);

    QLabel *sizeLabel = new QLabel("Si&ze");
    sizeLabel->setBuddy(m_cbSizeList);

    layout->addWidget(familyLabel);
    layout->addWidget(m_cbFamilyList);
    layout->addSpacing(5);
    layout->addWidget(styleLabel);
    layout->addWidget(m_cbStyleList);
    layout->addSpacing(5);
    layout->addWidget(sizeLabel);
    layout->addWidget(m_cbSizeList);

    connect(m_cbFamilyList, SIGNAL(currentTextChanged(QString)),
            SLOT(fontFamilyChanged(QString)));
    m_cbFamilyList->setModel(new FontFamilyModel(this));
}

QFont FontPicker::textFont() const
{
    return QFontDatabase().font(
                m_cbFamilyList->currentText(),
                m_cbStyleList->currentText(),
                m_cbSizeList->currentText().toInt());
}

void FontPicker::fontFamilyChanged(const QString& family)
{
    // m_cbFamilyList->setFont(QFont(family));
    QString currentStyle = m_cbStyleList->currentText();
    m_styleModel->clear();
    bool hasCurrentStyle = false;
    foreach (QString style, QFontDatabase().styles(family)) {
        m_styleModel->appendRow(new QStandardItem(style));
        if (style == currentStyle)
            hasCurrentStyle = true;
    }
    if (hasCurrentStyle)
        m_cbStyleList->setCurrentText(currentStyle);
}
