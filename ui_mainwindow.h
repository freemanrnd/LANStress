/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *FloodTypeLayout;
    QRadioButton *RB_TCP;
    QRadioButton *RB_UDP;
    QWidget *formLayoutWidget;
    QFormLayout *TCPSettingsLayout;
    QLabel *L_ipaddr;
    QLineEdit *E_IPAddr;
    QLabel *L_flags;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *CB_CWR;
    QCheckBox *CB_ECN;
    QCheckBox *CB_URG;
    QCheckBox *CB_ACK;
    QCheckBox *CB_PSH;
    QCheckBox *CB_RST;
    QCheckBox *CB_SYN;
    QCheckBox *CB_FIN;
    QWidget *formLayoutWidget_2;
    QFormLayout *GenericSettingsLayout;
    QSpinBox *SB_Port;
    QLabel *L_PacketSize;
    QSpinBox *SB_PacketSize;
    QLabel *L_port;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ONOFFLayout;
    QPushButton *PB_ON;
    QPushButton *PB_OFF;
    QProgressBar *BAR_Load;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *L_FloodTime;
    QSpinBox *SB_FloodTime;
    QSpinBox *SB_SilentTime;
    QLabel *L_FloodFreq;
    QSpinBox *SB_FloodFreq;
    QLabel *L_SilentTime;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(622, 295);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 61, 261));
        FloodTypeLayout = new QVBoxLayout(verticalLayoutWidget);
        FloodTypeLayout->setObjectName(QString::fromUtf8("FloodTypeLayout"));
        FloodTypeLayout->setContentsMargins(0, 0, 0, 0);
        RB_TCP = new QRadioButton(verticalLayoutWidget);
        RB_TCP->setObjectName(QString::fromUtf8("RB_TCP"));

        FloodTypeLayout->addWidget(RB_TCP);

        RB_UDP = new QRadioButton(verticalLayoutWidget);
        RB_UDP->setObjectName(QString::fromUtf8("RB_UDP"));

        FloodTypeLayout->addWidget(RB_UDP);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(78, 10, 541, 101));
        TCPSettingsLayout = new QFormLayout(formLayoutWidget);
        TCPSettingsLayout->setObjectName(QString::fromUtf8("TCPSettingsLayout"));
        TCPSettingsLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        TCPSettingsLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        TCPSettingsLayout->setContentsMargins(0, 0, 0, 0);
        L_ipaddr = new QLabel(formLayoutWidget);
        L_ipaddr->setObjectName(QString::fromUtf8("L_ipaddr"));
        L_ipaddr->setEnabled(true);

        TCPSettingsLayout->setWidget(0, QFormLayout::LabelRole, L_ipaddr);

        E_IPAddr = new QLineEdit(formLayoutWidget);
        E_IPAddr->setObjectName(QString::fromUtf8("E_IPAddr"));
        E_IPAddr->setEnabled(false);

        TCPSettingsLayout->setWidget(0, QFormLayout::FieldRole, E_IPAddr);

        L_flags = new QLabel(formLayoutWidget);
        L_flags->setObjectName(QString::fromUtf8("L_flags"));
        L_flags->setEnabled(true);

        TCPSettingsLayout->setWidget(1, QFormLayout::LabelRole, L_flags);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        CB_CWR = new QCheckBox(formLayoutWidget);
        CB_CWR->setObjectName(QString::fromUtf8("CB_CWR"));
        CB_CWR->setEnabled(false);

        horizontalLayout_3->addWidget(CB_CWR);

        CB_ECN = new QCheckBox(formLayoutWidget);
        CB_ECN->setObjectName(QString::fromUtf8("CB_ECN"));
        CB_ECN->setEnabled(false);

        horizontalLayout_3->addWidget(CB_ECN);

        CB_URG = new QCheckBox(formLayoutWidget);
        CB_URG->setObjectName(QString::fromUtf8("CB_URG"));
        CB_URG->setEnabled(false);

        horizontalLayout_3->addWidget(CB_URG);

        CB_ACK = new QCheckBox(formLayoutWidget);
        CB_ACK->setObjectName(QString::fromUtf8("CB_ACK"));
        CB_ACK->setEnabled(false);

        horizontalLayout_3->addWidget(CB_ACK);

        CB_PSH = new QCheckBox(formLayoutWidget);
        CB_PSH->setObjectName(QString::fromUtf8("CB_PSH"));
        CB_PSH->setEnabled(false);

        horizontalLayout_3->addWidget(CB_PSH);

        CB_RST = new QCheckBox(formLayoutWidget);
        CB_RST->setObjectName(QString::fromUtf8("CB_RST"));
        CB_RST->setEnabled(false);

        horizontalLayout_3->addWidget(CB_RST);

        CB_SYN = new QCheckBox(formLayoutWidget);
        CB_SYN->setObjectName(QString::fromUtf8("CB_SYN"));
        CB_SYN->setEnabled(false);

        horizontalLayout_3->addWidget(CB_SYN);

        CB_FIN = new QCheckBox(formLayoutWidget);
        CB_FIN->setObjectName(QString::fromUtf8("CB_FIN"));
        CB_FIN->setEnabled(false);

        horizontalLayout_3->addWidget(CB_FIN);


        TCPSettingsLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);

        formLayoutWidget_2 = new QWidget(centralwidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(80, 120, 221, 91));
        GenericSettingsLayout = new QFormLayout(formLayoutWidget_2);
        GenericSettingsLayout->setObjectName(QString::fromUtf8("GenericSettingsLayout"));
        GenericSettingsLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        GenericSettingsLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        GenericSettingsLayout->setFormAlignment(Qt::AlignCenter);
        GenericSettingsLayout->setContentsMargins(0, 0, 0, 0);
        SB_Port = new QSpinBox(formLayoutWidget_2);
        SB_Port->setObjectName(QString::fromUtf8("SB_Port"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SB_Port->sizePolicy().hasHeightForWidth());
        SB_Port->setSizePolicy(sizePolicy);
        SB_Port->setMinimum(0);
        SB_Port->setMaximum(65535);

        GenericSettingsLayout->setWidget(0, QFormLayout::FieldRole, SB_Port);

        L_PacketSize = new QLabel(formLayoutWidget_2);
        L_PacketSize->setObjectName(QString::fromUtf8("L_PacketSize"));

        GenericSettingsLayout->setWidget(1, QFormLayout::LabelRole, L_PacketSize);

        SB_PacketSize = new QSpinBox(formLayoutWidget_2);
        SB_PacketSize->setObjectName(QString::fromUtf8("SB_PacketSize"));
        sizePolicy.setHeightForWidth(SB_PacketSize->sizePolicy().hasHeightForWidth());
        SB_PacketSize->setSizePolicy(sizePolicy);
        SB_PacketSize->setMaximum(65000);
        SB_PacketSize->setValue(1000);

        GenericSettingsLayout->setWidget(1, QFormLayout::FieldRole, SB_PacketSize);

        L_port = new QLabel(formLayoutWidget_2);
        L_port->setObjectName(QString::fromUtf8("L_port"));

        GenericSettingsLayout->setWidget(0, QFormLayout::LabelRole, L_port);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 220, 281, 51));
        ONOFFLayout = new QHBoxLayout(horizontalLayoutWidget);
        ONOFFLayout->setObjectName(QString::fromUtf8("ONOFFLayout"));
        ONOFFLayout->setContentsMargins(0, 0, 0, 0);
        PB_ON = new QPushButton(horizontalLayoutWidget);
        PB_ON->setObjectName(QString::fromUtf8("PB_ON"));
        PB_ON->setEnabled(false);

        ONOFFLayout->addWidget(PB_ON);

        PB_OFF = new QPushButton(horizontalLayoutWidget);
        PB_OFF->setObjectName(QString::fromUtf8("PB_OFF"));
        PB_OFF->setEnabled(false);

        ONOFFLayout->addWidget(PB_OFF);

        BAR_Load = new QProgressBar(centralwidget);
        BAR_Load->setObjectName(QString::fromUtf8("BAR_Load"));
        BAR_Load->setEnabled(false);
        BAR_Load->setGeometry(QRect(380, 240, 231, 23));
        BAR_Load->setValue(0);
        BAR_Load->setTextVisible(false);
        formLayoutWidget_3 = new QWidget(centralwidget);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(310, 120, 309, 91));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        L_FloodTime = new QLabel(formLayoutWidget_3);
        L_FloodTime->setObjectName(QString::fromUtf8("L_FloodTime"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, L_FloodTime);

        SB_FloodTime = new QSpinBox(formLayoutWidget_3);
        SB_FloodTime->setObjectName(QString::fromUtf8("SB_FloodTime"));
        sizePolicy.setHeightForWidth(SB_FloodTime->sizePolicy().hasHeightForWidth());
        SB_FloodTime->setSizePolicy(sizePolicy);
        SB_FloodTime->setMaximum(3000);
        SB_FloodTime->setSingleStep(100);
        SB_FloodTime->setValue(1000);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, SB_FloodTime);

        SB_SilentTime = new QSpinBox(formLayoutWidget_3);
        SB_SilentTime->setObjectName(QString::fromUtf8("SB_SilentTime"));
        sizePolicy.setHeightForWidth(SB_SilentTime->sizePolicy().hasHeightForWidth());
        SB_SilentTime->setSizePolicy(sizePolicy);
        SB_SilentTime->setMaximum(3000);
        SB_SilentTime->setSingleStep(100);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, SB_SilentTime);

        L_FloodFreq = new QLabel(formLayoutWidget_3);
        L_FloodFreq->setObjectName(QString::fromUtf8("L_FloodFreq"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, L_FloodFreq);

        SB_FloodFreq = new QSpinBox(formLayoutWidget_3);
        SB_FloodFreq->setObjectName(QString::fromUtf8("SB_FloodFreq"));
        sizePolicy.setHeightForWidth(SB_FloodFreq->sizePolicy().hasHeightForWidth());
        SB_FloodFreq->setSizePolicy(sizePolicy);
        SB_FloodFreq->setMaximum(1000000);
        SB_FloodFreq->setSingleStep(100);
        SB_FloodFreq->setValue(1000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, SB_FloodFreq);

        L_SilentTime = new QLabel(formLayoutWidget_3);
        L_SilentTime->setObjectName(QString::fromUtf8("L_SilentTime"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, L_SilentTime);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#ifndef QT_NO_SHORTCUT
        L_ipaddr->setBuddy(E_IPAddr);
        L_PacketSize->setBuddy(SB_PacketSize);
        L_port->setBuddy(SB_Port);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(RB_UDP, RB_TCP);
        QWidget::setTabOrder(RB_TCP, E_IPAddr);
        QWidget::setTabOrder(E_IPAddr, CB_CWR);
        QWidget::setTabOrder(CB_CWR, CB_ECN);
        QWidget::setTabOrder(CB_ECN, CB_URG);
        QWidget::setTabOrder(CB_URG, CB_ACK);
        QWidget::setTabOrder(CB_ACK, CB_PSH);
        QWidget::setTabOrder(CB_PSH, CB_RST);
        QWidget::setTabOrder(CB_RST, CB_SYN);
        QWidget::setTabOrder(CB_SYN, CB_FIN);
        QWidget::setTabOrder(CB_FIN, SB_Port);
        QWidget::setTabOrder(SB_Port, SB_PacketSize);
        QWidget::setTabOrder(SB_PacketSize, PB_ON);
        QWidget::setTabOrder(PB_ON, PB_OFF);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LANStress - \321\215\320\274\321\203\320\273\321\217\321\206\320\270\321\217 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\275\320\260 \320\273\320\276\320\272\320\260\320\273\321\214\320\275\321\203\321\216 \321\201\320\265\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RB_TCP->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\206\320\265\320\273\320\265\320\262\320\276\320\263\320\276 \321\205\320\276\321\201\321\202\320\260 TCP \320\277\320\260\320\272\320\265\321\202\320\260\320\274\320\270 \321\201\320\276 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\274 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\321\213\320\274", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        RB_TCP->setWhatsThis(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\206\320\265\320\273\320\265\320\262\320\276\320\263\320\276 \321\205\320\276\321\201\321\202\320\260 TCP \320\277\320\260\320\272\320\265\321\202\320\260\320\274\320\270 \321\201\320\276 \321\201\320\273\321\203\321\207\320\260\320\271\320\275\321\213\320\274 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\321\213\320\274", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        RB_TCP->setText(QApplication::translate("MainWindow", "TCP", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        RB_UDP->setToolTip(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\210\320\270\321\200\320\276\320\272\320\276\320\262\320\265\321\211\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270 UDP \320\277\320\260\320\272\320\265\321\202\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        RB_UDP->setWhatsThis(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\210\320\270\321\200\320\276\320\272\320\276\320\262\320\265\321\211\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270 UDP \320\277\320\260\320\272\320\265\321\202\320\260\320\274\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        RB_UDP->setText(QApplication::translate("MainWindow", "UDP", 0, QApplication::UnicodeUTF8));
        L_ipaddr->setText(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        E_IPAddr->setToolTip(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \321\206\320\265\320\273\320\270 \320\277\320\260\320\272\320\265\321\202\320\260", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        E_IPAddr->setWhatsThis(QApplication::translate("MainWindow", "IP \320\260\320\264\321\200\320\265\321\201 \321\206\320\265\320\273\320\270 \320\277\320\260\320\272\320\265\321\202\320\260 (4 \321\207\320\270\321\201\320\273\320\260 \320\276\321\202 0 \320\264\320\276 255, \321\200\320\260\320\267\320\264\320\265\320\273\321\221\320\275\320\275\321\213\320\265 \321\202\320\276\321\207\320\272\320\260\320\274\320\270)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        E_IPAddr->setInputMask(QApplication::translate("MainWindow", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        L_flags->setText(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263\320\270", 0, QApplication::UnicodeUTF8));
        CB_CWR->setText(QApplication::translate("MainWindow", "CWR", 0, QApplication::UnicodeUTF8));
        CB_ECN->setText(QApplication::translate("MainWindow", "ECN", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_URG->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\262\320\260\320\266\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_URG->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\262\320\260\320\266\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_URG->setText(QApplication::translate("MainWindow", "URG", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_ACK->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_ACK->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\277\320\276\320\264\321\202\320\262\320\265\321\200\320\266\320\264\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_ACK->setText(QApplication::translate("MainWindow", "ACK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_PSH->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\277\321\200\320\276\321\202\320\260\320\273\320\272\320\270\320\262\320\260\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_PSH->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\277\321\200\320\276\321\202\320\260\320\273\320\272\320\270\320\262\320\260\320\275\320\270\321\217 (\321\201\320\261\321\200\320\276\321\201 \320\261\321\203\321\204\320\265\321\200\320\260 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\321\216\321\211\320\265\320\271 \321\201\321\202\320\276\321\200\320\276\320\275\321\213)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_PSH->setText(QApplication::translate("MainWindow", "PSH", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_RST->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \321\201\320\261\321\200\320\276\321\201\320\260 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_RST->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \321\201\320\261\321\200\320\276\321\201\320\260 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_RST->setText(QApplication::translate("MainWindow", "RST", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_SYN->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_SYN->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \321\201\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\260\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_SYN->setText(QApplication::translate("MainWindow", "SYN", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CB_FIN->setToolTip(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\321\217 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        CB_FIN->setWhatsThis(QApplication::translate("MainWindow", "\320\244\320\273\320\260\320\263 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\321\217 \321\201\320\276\320\265\320\264\320\270\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        CB_FIN->setText(QApplication::translate("MainWindow", "FIN", 0, QApplication::UnicodeUTF8));
        L_PacketSize->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\260\320\272\320\265\321\202\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SB_PacketSize->setToolTip(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\260\320\272\320\265\321\202\320\260 \320\262 \320\261\320\260\320\271\321\202\320\260\321\205 (\320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276 65K)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        SB_PacketSize->setWhatsThis(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\260\320\272\320\265\321\202\320\260 \320\262 \320\261\320\260\320\271\321\202\320\260\321\205 (\320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276 65K)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        SB_PacketSize->setSuffix(QApplication::translate("MainWindow", " \320\261\320\260\320\271\321\202", 0, QApplication::UnicodeUTF8));
        L_port->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\200\321\202 \320\277\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\217", 0, QApplication::UnicodeUTF8));
        PB_ON->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        PB_OFF->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        L_FloodTime->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\263\321\200\321\203\320\267\320\272\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SB_FloodTime->setToolTip(QApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\320\276\320\273\320\266\320\270\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\277\320\265\321\200\320\270\320\276\320\264\320\260 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\270 (\320\265\321\201\320\273\320\270 \321\202\320\270\321\210\320\270\320\275\320\260 \320\261\320\276\320\273\321\214\321\210\320\265 0)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SB_FloodTime->setSuffix(QApplication::translate("MainWindow", "\320\274\321\201", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SB_SilentTime->setToolTip(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \321\202\320\270\321\210\320\270\320\275\321\213 \320\262 \320\274\320\270\320\273\320\273\320\270\321\201\320\265\320\272\321\203\320\275\320\264\320\260\321\205", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        SB_SilentTime->setWhatsThis(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264 \321\202\320\270\321\210\320\270\320\275\321\213 \320\262 \320\274\320\270\320\273\320\273\320\270\321\201\320\265\320\272\321\203\320\275\320\264\320\260\321\205", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        SB_SilentTime->setSuffix(QApplication::translate("MainWindow", "\320\274\321\201", 0, QApplication::UnicodeUTF8));
        L_FloodFreq->setText(QApplication::translate("MainWindow", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SB_FloodFreq->setToolTip(QApplication::translate("MainWindow", "\320\237\320\260\320\272\320\265\321\202\320\276\320\262 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\321\203 \320\277\321\200\320\270 \321\201\321\200\320\265\320\264\320\275\320\265\320\271 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\265 (0 - \320\277\320\270\320\272\320\276\320\262\320\260\321\217 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\260)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        SB_FloodFreq->setWhatsThis(QApplication::translate("MainWindow", "\320\237\320\260\320\272\320\265\321\202\320\276\320\262 \320\262 \321\201\320\265\320\272\321\203\320\275\320\264\321\203 \320\277\321\200\320\270 \321\201\321\200\320\265\320\264\320\275\320\265\320\271 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\265 (0 - \320\277\320\270\320\272\320\276\320\262\320\260\321\217 \320\275\320\260\320\263\321\200\321\203\320\267\320\272\320\260)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        SB_FloodFreq->setSuffix(QApplication::translate("MainWindow", "\320\277/\321\201", 0, QApplication::UnicodeUTF8));
        L_SilentTime->setText(QApplication::translate("MainWindow", "\320\242\320\270\321\210\320\270\320\275\320\260", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
