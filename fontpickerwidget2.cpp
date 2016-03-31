#include "fontpickerwidget2.h"
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include "fontlistmodel.h"

static void selectClosestSize(QComboBox *cb, int desiredSize)
{
    int bestSize, bestIndex = -1;
    for (int i=0, n=cb->count(); i<n; ++i)
    {
        int size = cb->itemData(i, Qt::DisplayRole).toInt();
        if (bestIndex == -1   ||
                abs(size-desiredSize) < abs(bestSize-desiredSize))
        {
            bestSize = size;
            bestIndex = i;
        }
    }
    cb->setCurrentIndex(bestIndex);
}

FontPickerWidget2::FontPickerWidget2(QWidget *parent) : QWidget(parent)
{
    auto layout = new QHBoxLayout(this);
    layout->setMargin(0);

    m_cbFamilyList = new QComboBox;
    m_styleModel = new QStandardItemModel(this);
    m_cbStyleList = new QComboBox;
    m_cbStyleList->setModel(m_styleModel);
    m_cbSizeList = new QComboBox;

    auto sizeModel = new QStandardItemModel(this);
    foreach (int size, QFontDatabase::standardSizes())
        sizeModel->appendRow(new QStandardItem(QString::number(size)));
    m_cbSizeList->setModel(sizeModel);

    connect(m_cbFamilyList, SIGNAL(currentIndexChanged(int)), SLOT(fontFamilyChanged()));
    m_cbFamilyList->setModel(new FontListModel(this));
    m_cbFamilyList->setCurrentText(font().family());
    auto familyLabel = new QLabel("F&amily");
    familyLabel->setBuddy(m_cbFamilyList);

    auto styleLabel = new QLabel("St&yle");
    styleLabel->setBuddy(m_cbStyleList);

    auto sizeLabel = new QLabel("&Size");
    sizeLabel->setBuddy(m_cbSizeList);
    selectClosestSize(m_cbSizeList, 12);

    layout->addWidget(familyLabel);
    layout->addWidget(m_cbFamilyList);
    layout->addSpacing(5);
    layout->addWidget(styleLabel);
    layout->addWidget(m_cbStyleList);
    layout->addSpacing(5);
    layout->addWidget(sizeLabel);
    layout->addWidget(m_cbSizeList);
}

void FontPickerWidget2::fontFamilyChanged()
{
    QFont font = m_cbFamilyList->currentData(Qt::FontRole).value<QFont>();
    font.setPixelSize(12);
    m_cbFamilyList->setFont(font);

    QString currentStyle = m_cbStyleList->currentText();
    m_styleModel->clear();
    bool hasCurrentStyle = false;
    foreach (QString style, QFontDatabase().styles(font.family())) {
        m_styleModel->appendRow(new QStandardItem(style));
        if (currentStyle == style)
            hasCurrentStyle = true;
    }
    if (hasCurrentStyle)
        m_cbStyleList->setCurrentText(currentStyle);
}

QFont FontPickerWidget2::selectedFont() const
{
    QString family = m_cbFamilyList->currentText();
    QString style = m_cbStyleList->currentText();
    int size = m_cbSizeList->currentText().toInt();
    return QFontDatabase().font(family, style, size);
}
