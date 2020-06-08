# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'GoldenBox.ui'
##
## Created by: Qt User Interface Compiler version 5.14.0
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################
import sys
from PySide2.QtCore import (QCoreApplication, QMetaObject, QObject, QPoint,
    QRect, QSize, QUrl, Qt , SIGNAL)
from PySide2.QtGui import (QBrush, QColor, QConicalGradient, QFont,
    QFontDatabase, QIcon, QLinearGradient, QPalette, QPainter, QPixmap,
    QRadialGradient)
from PySide2.QtWidgets import *

class Ui_GoldenBox_Form(object):
    def setupUi(self, GoldenBox_Form):
        if GoldenBox_Form.objectName():
            GoldenBox_Form.setObjectName(u"GoldenBox_Form")
        GoldenBox_Form.resize(1043, 803)
        self.gridLayout_8 = QGridLayout(GoldenBox_Form)
        self.gridLayout_8.setObjectName(u"gridLayout_8")
        self.formLayout = QFormLayout()
        self.formLayout.setObjectName(u"formLayout")
        self.MainTabs = QTabWidget(GoldenBox_Form)
        self.MainTabs.setObjectName(u"MainTabs")
        self.Welcome = QWidget()
        self.Welcome.setObjectName(u"Welcome")
        self.gridLayout_25 = QGridLayout(self.Welcome)
        self.gridLayout_25.setObjectName(u"gridLayout_25")
        self.label_3 = QLabel(self.Welcome)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setFrameShape(QFrame.NoFrame)
        self.label_3.setFrameShadow(QFrame.Plain)
        self.label_3.setLineWidth(50)
        self.label_3.setMidLineWidth(50)
        self.label_3.setTextFormat(Qt.AutoText)
        self.label_3.setAlignment(Qt.AlignCenter)
        self.label_3.setWordWrap(False)
        self.label_3.setIndent(-1)
        self.label_3.setOpenExternalLinks(False)
        self.label_3.setTextInteractionFlags(Qt.NoTextInteraction)

        self.gridLayout_25.addWidget(self.label_3, 0, 0, 1, 1)

        self.MainTabs.addTab(self.Welcome, "")
        self.Peripherals = QWidget()
        self.Peripherals.setObjectName(u"Peripherals")
        self.gridLayout_7 = QGridLayout(self.Peripherals)
        self.gridLayout_7.setObjectName(u"gridLayout_7")
        self.PeripheralTabs = QTabWidget(self.Peripherals)
        self.PeripheralTabs.setObjectName(u"PeripheralTabs")
        self.Main = QWidget()
        self.Main.setObjectName(u"Main")
        self.gridLayout = QGridLayout(self.Main)
        self.gridLayout.setObjectName(u"gridLayout")
        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.horizontalLayout_22 = QHBoxLayout()
        self.horizontalLayout_22.setObjectName(u"horizontalLayout_22")
        self.gridLayout_2 = QGridLayout()
        self.gridLayout_2.setObjectName(u"gridLayout_2")
        self.MainTabs_2 = QTabWidget(self.Main)
        self.MainTabs_2.setObjectName(u"MainTabs_2")
        self.DIO = QWidget()
        self.DIO.setObjectName(u"DIO")
        self.horizontalLayoutWidget = QWidget(self.DIO)
        self.horizontalLayoutWidget.setObjectName(u"horizontalLayoutWidget")
        self.horizontalLayoutWidget.setGeometry(QRect(0, 0, 491, 571))
        self.horizontalLayout = QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.DIGT_IN_CH_groupBox = QGroupBox(self.horizontalLayoutWidget)
        self.DIGT_IN_CH_groupBox.setObjectName(u"DIGT_IN_CH_groupBox")
        self.DIGT_IN_CH_groupBox.setSizeIncrement(QSize(2, 2))
        font = QFont()
        font.setPointSize(9)
        font.setBold(True)
        font.setWeight(75);
        self.DIGT_IN_CH_groupBox.setFont(font)
        self.DIGT_IN_CH00_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH00_GB.setObjectName(u"DIGT_IN_CH00_GB")
        self.DIGT_IN_CH00_GB.setGeometry(QRect(0, 50, 491, 51))
        self.plainTextEdit_8 = QPlainTextEdit(self.DIGT_IN_CH00_GB)
        self.plainTextEdit_8.setObjectName(u"plainTextEdit_8")
        self.plainTextEdit_8.setGeometry(QRect(120, 10, 91, 31))
        self.DIGT_IN_CH01_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH01_GB.setObjectName(u"DIGT_IN_CH01_GB")
        self.DIGT_IN_CH01_GB.setGeometry(QRect(0, 100, 491, 61))
        self.plainTextEdit_7 = QPlainTextEdit(self.DIGT_IN_CH01_GB)
        self.plainTextEdit_7.setObjectName(u"plainTextEdit_7")
        self.plainTextEdit_7.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH02_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH02_GB.setObjectName(u"DIGT_IN_CH02_GB")
        self.DIGT_IN_CH02_GB.setGeometry(QRect(0, 160, 491, 61))
        self.plainTextEdit = QPlainTextEdit(self.DIGT_IN_CH02_GB)
        self.plainTextEdit.setObjectName(u"plainTextEdit")
        self.plainTextEdit.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH03_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH03_GB.setObjectName(u"DIGT_IN_CH03_GB")
        self.DIGT_IN_CH03_GB.setGeometry(QRect(0, 220, 491, 61))
        self.plainTextEdit_2 = QPlainTextEdit(self.DIGT_IN_CH03_GB)
        self.plainTextEdit_2.setObjectName(u"plainTextEdit_2")
        self.plainTextEdit_2.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH04_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH04_GB.setObjectName(u"DIGT_IN_CH04_GB")
        self.DIGT_IN_CH04_GB.setGeometry(QRect(0, 280, 491, 61))
        self.plainTextEdit_3 = QPlainTextEdit(self.DIGT_IN_CH04_GB)
        self.plainTextEdit_3.setObjectName(u"plainTextEdit_3")
        self.plainTextEdit_3.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH05_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH05_GB.setObjectName(u"DIGT_IN_CH05_GB")
        self.DIGT_IN_CH05_GB.setGeometry(QRect(0, 340, 491, 61))
        self.plainTextEdit_4 = QPlainTextEdit(self.DIGT_IN_CH05_GB)
        self.plainTextEdit_4.setObjectName(u"plainTextEdit_4")
        self.plainTextEdit_4.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH06_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH06_GB.setObjectName(u"DIGT_IN_CH06_GB")
        self.DIGT_IN_CH06_GB.setGeometry(QRect(0, 410, 491, 61))
        self.plainTextEdit_5 = QPlainTextEdit(self.DIGT_IN_CH06_GB)
        self.plainTextEdit_5.setObjectName(u"plainTextEdit_5")
        self.plainTextEdit_5.setGeometry(QRect(120, 20, 91, 31))
        self.DIGT_IN_CH07_GB = QGroupBox(self.DIGT_IN_CH_groupBox)
        self.DIGT_IN_CH07_GB.setObjectName(u"DIGT_IN_CH07_GB")
        self.DIGT_IN_CH07_GB.setGeometry(QRect(0, 470, 491, 61))
        self.plainTextEdit_6 = QPlainTextEdit(self.DIGT_IN_CH07_GB)
        self.plainTextEdit_6.setObjectName(u"plainTextEdit_6")
        self.plainTextEdit_6.setGeometry(QRect(120, 20, 91, 31))

        self.horizontalLayout.addWidget(self.DIGT_IN_CH_groupBox)

        self.horizontalLayoutWidget_2 = QWidget(self.DIO)
        self.horizontalLayoutWidget_2.setObjectName(u"horizontalLayoutWidget_2")
        self.horizontalLayoutWidget_2.setGeometry(QRect(489, 0, 481, 571))
        self.horizontalLayout_2 = QHBoxLayout(self.horizontalLayoutWidget_2)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.DIGT_OUT_CH_groupBox = QGroupBox(self.horizontalLayoutWidget_2)
        self.DIGT_OUT_CH_groupBox.setObjectName(u"DIGT_OUT_CH_groupBox")
        font1 = QFont()
        font1.setPointSize(10)
        font1.setBold(True)
        font1.setWeight(75);
        self.DIGT_OUT_CH_groupBox.setFont(font1)
        self.DIGT_OUT_CH08_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH08_GB.setObjectName(u"DIGT_OUT_CH08_GB")
        self.DIGT_OUT_CH08_GB.setGeometry(QRect(0, 50, 491, 51))
        self.DIGT_OUT_LOW_CH08_RB = QRadioButton(self.DIGT_OUT_CH08_GB)
        self.DIGT_OUT_LOW_CH08_RB.setObjectName(u"DIGT_OUT_LOW_CH08_RB")
        self.DIGT_OUT_LOW_CH08_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH08_RB = QRadioButton(self.DIGT_OUT_CH08_GB)
        self.DIGT_OUT_HI_CH08_RB.setObjectName(u"DIGT_OUT_HI_CH08_RB")
        self.DIGT_OUT_HI_CH08_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH09_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH09_GB.setObjectName(u"DIGT_OUT_CH09_GB")
        self.DIGT_OUT_CH09_GB.setGeometry(QRect(0, 100, 491, 61))
        self.DIGT_OUT_LOW_CH09_RB = QRadioButton(self.DIGT_OUT_CH09_GB)
        self.DIGT_OUT_LOW_CH09_RB.setObjectName(u"DIGT_OUT_LOW_CH09_RB")
        self.DIGT_OUT_LOW_CH09_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH09_RB = QRadioButton(self.DIGT_OUT_CH09_GB)
        self.DIGT_OUT_HI_CH09_RB.setObjectName(u"DIGT_OUT_HI_CH09_RB")
        self.DIGT_OUT_HI_CH09_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH10_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH10_GB.setObjectName(u"DIGT_OUT_CH10_GB")
        self.DIGT_OUT_CH10_GB.setGeometry(QRect(0, 160, 491, 61))
        self.DIGT_OUT_LOW_CH10_RB = QRadioButton(self.DIGT_OUT_CH10_GB)
        self.DIGT_OUT_LOW_CH10_RB.setObjectName(u"DIGT_OUT_LOW_CH10_RB")
        self.DIGT_OUT_LOW_CH10_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH10_RB = QRadioButton(self.DIGT_OUT_CH10_GB)
        self.DIGT_OUT_HI_CH10_RB.setObjectName(u"DIGT_OUT_HI_CH10_RB")
        self.DIGT_OUT_HI_CH10_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH11_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH11_GB.setObjectName(u"DIGT_OUT_CH11_GB")
        self.DIGT_OUT_CH11_GB.setGeometry(QRect(0, 220, 491, 61))
        self.DIGT_OUT_LOW_CH11_RB = QRadioButton(self.DIGT_OUT_CH11_GB)
        self.DIGT_OUT_LOW_CH11_RB.setObjectName(u"DIGT_OUT_LOW_CH11_RB")
        self.DIGT_OUT_LOW_CH11_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH11_RB = QRadioButton(self.DIGT_OUT_CH11_GB)
        self.DIGT_OUT_HI_CH11_RB.setObjectName(u"DIGT_OUT_HI_CH11_RB")
        self.DIGT_OUT_HI_CH11_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH12_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH12_GB.setObjectName(u"DIGT_OUT_CH12_GB")
        self.DIGT_OUT_CH12_GB.setGeometry(QRect(0, 280, 491, 61))
        self.DIGT_OUT_LOW_CH12_RB = QRadioButton(self.DIGT_OUT_CH12_GB)
        self.DIGT_OUT_LOW_CH12_RB.setObjectName(u"DIGT_OUT_LOW_CH12_RB")
        self.DIGT_OUT_LOW_CH12_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH12_RB = QRadioButton(self.DIGT_OUT_CH12_GB)
        self.DIGT_OUT_HI_CH12_RB.setObjectName(u"DIGT_OUT_HI_CH12_RB")
        self.DIGT_OUT_HI_CH12_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH13_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH13_GB.setObjectName(u"DIGT_OUT_CH13_GB")
        self.DIGT_OUT_CH13_GB.setGeometry(QRect(0, 340, 491, 61))
        self.DIGT_OUT_LOW_CH13_RB = QRadioButton(self.DIGT_OUT_CH13_GB)
        self.DIGT_OUT_LOW_CH13_RB.setObjectName(u"DIGT_OUT_LOW_CH13_RB")
        self.DIGT_OUT_LOW_CH13_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH13_RB = QRadioButton(self.DIGT_OUT_CH13_GB)
        self.DIGT_OUT_HI_CH13_RB.setObjectName(u"DIGT_OUT_HI_CH13_RB")
        self.DIGT_OUT_HI_CH13_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH14_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH14_GB.setObjectName(u"DIGT_OUT_CH14_GB")
        self.DIGT_OUT_CH14_GB.setGeometry(QRect(0, 410, 491, 61))
        self.DIGT_OUT_LOW_CH14_RB = QRadioButton(self.DIGT_OUT_CH14_GB)
        self.DIGT_OUT_LOW_CH14_RB.setObjectName(u"DIGT_OUT_LOW_CH14_RB")
        self.DIGT_OUT_LOW_CH14_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH14_RB = QRadioButton(self.DIGT_OUT_CH14_GB)
        self.DIGT_OUT_HI_CH14_RB.setObjectName(u"DIGT_OUT_HI_CH14_RB")
        self.DIGT_OUT_HI_CH14_RB.setGeometry(QRect(160, 20, 83, 18))
        self.DIGT_OUT_CH15_GB = QGroupBox(self.DIGT_OUT_CH_groupBox)
        self.DIGT_OUT_CH15_GB.setObjectName(u"DIGT_OUT_CH15_GB")
        self.DIGT_OUT_CH15_GB.setGeometry(QRect(0, 470, 491, 61))
        self.DIGT_OUT_LOW_CH15_RB = QRadioButton(self.DIGT_OUT_CH15_GB)
        self.DIGT_OUT_LOW_CH15_RB.setObjectName(u"DIGT_OUT_LOW_CH15_RB")
        self.DIGT_OUT_LOW_CH15_RB.setGeometry(QRect(330, 20, 83, 18))
        self.DIGT_OUT_HI_CH15_RB = QRadioButton(self.DIGT_OUT_CH15_GB)
        self.DIGT_OUT_HI_CH15_RB.setObjectName(u"DIGT_OUT_HI_CH15_RB")
        self.DIGT_OUT_HI_CH15_RB.setGeometry(QRect(160, 20, 83, 18))

        self.horizontalLayout_2.addWidget(self.DIGT_OUT_CH_groupBox)

        self.MainTabs_2.addTab(self.DIO, "")
        self.ADC = QWidget()
        self.ADC.setObjectName(u"ADC")
        self.MainTabs_2.addTab(self.ADC, "")
        self.tab = QWidget()
        self.tab.setObjectName(u"tab")
        self.MainTabs_2.addTab(self.tab, "")

        self.gridLayout_2.addWidget(self.MainTabs_2, 0, 0, 1, 1)


        self.horizontalLayout_22.addLayout(self.gridLayout_2)


        self.verticalLayout_2.addLayout(self.horizontalLayout_22)

        self.verticalSpacer = QSpacerItem(20, 30, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.verticalLayout_2.addItem(self.verticalSpacer)

        self.gridLayout_20 = QGridLayout()
        self.gridLayout_20.setObjectName(u"gridLayout_20")
        self.horizontalSpacer_5 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.gridLayout_20.addItem(self.horizontalSpacer_5, 0, 0, 1, 1)

        self.update_btn = QPushButton(self.Main)
        self.update_btn.setObjectName(u"update_btn")
        sizePolicy = QSizePolicy(QSizePolicy.Minimum, QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.update_btn.sizePolicy().hasHeightForWidth())
        self.update_btn.setSizePolicy(sizePolicy)
        self.update_btn.setMinimumSize(QSize(150, 0))

        self.gridLayout_20.addWidget(self.update_btn, 0, 1, 1, 1)

        self.horizontalSpacer_6 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.gridLayout_20.addItem(self.horizontalSpacer_6, 0, 2, 1, 1)


        self.verticalLayout_2.addLayout(self.gridLayout_20)

        self.verticalSpacer_2 = QSpacerItem(20, 20, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.verticalLayout_2.addItem(self.verticalSpacer_2)


        self.gridLayout.addLayout(self.verticalLayout_2, 0, 0, 1, 1)

        self.PeripheralTabs.addTab(self.Main, "")
        self.communication = QWidget()
        self.communication.setObjectName(u"communication")
        self.PeripheralTabs.addTab(self.communication, "")

        self.gridLayout_7.addWidget(self.PeripheralTabs, 0, 0, 1, 1)

        self.MainTabs.addTab(self.Peripherals, "")
        self.Settings = QWidget()
        self.Settings.setObjectName(u"Settings")
        self.gridLayout_22 = QGridLayout(self.Settings)
        self.gridLayout_22.setObjectName(u"gridLayout_22")
        self.groupBox_17 = QGroupBox(self.Settings)
        self.groupBox_17.setObjectName(u"groupBox_17")
        self.gridLayout_21 = QGridLayout(self.groupBox_17)
        self.gridLayout_21.setObjectName(u"gridLayout_21")
        self.gridLayout_23 = QGridLayout()
        self.gridLayout_23.setObjectName(u"gridLayout_23")
        self.gridLayout_24 = QGridLayout()
        self.gridLayout_24.setObjectName(u"gridLayout_24")
        self.horizontalSpacer = QSpacerItem(30, 0, QSizePolicy.Preferred, QSizePolicy.Minimum)

        self.gridLayout_24.addItem(self.horizontalSpacer, 6, 0, 1, 1)

        self.verticalSpacer_3 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_24.addItem(self.verticalSpacer_3, 5, 1, 1, 1)

        self.connection_btn_stop = QPushButton(self.groupBox_17)
        self.connection_btn_stop.setObjectName(u"connection_btn_stop")
        sizePolicy1 = QSizePolicy(QSizePolicy.Maximum, QSizePolicy.Fixed)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.connection_btn_stop.sizePolicy().hasHeightForWidth())
        self.connection_btn_stop.setSizePolicy(sizePolicy1)

        self.gridLayout_24.addWidget(self.connection_btn_stop, 4, 1, 1, 1)

        self.label_2 = QLabel(self.groupBox_17)
        self.label_2.setObjectName(u"label_2")

        self.gridLayout_24.addWidget(self.label_2, 1, 0, 1, 1)

        self.verticalSpacer_6 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_24.addItem(self.verticalSpacer_6, 11, 1, 1, 1)

        self.verticalSpacer_5 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_24.addItem(self.verticalSpacer_5, 10, 1, 1, 1)

        self.connection_textbox_serverip = QLineEdit(self.groupBox_17)
        self.connection_textbox_serverip.setObjectName(u"connection_textbox_serverip")
        sizePolicy2 = QSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
        sizePolicy2.setHorizontalStretch(0)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.connection_textbox_serverip.sizePolicy().hasHeightForWidth())
        self.connection_textbox_serverip.setSizePolicy(sizePolicy2)
        self.connection_textbox_serverip.setMaxLength(32767)
        self.connection_textbox_serverip.setFrame(True)
        self.connection_textbox_serverip.setDragEnabled(False)

        self.gridLayout_24.addWidget(self.connection_textbox_serverip, 0, 1, 1, 1)

        self.label = QLabel(self.groupBox_17)
        self.label.setObjectName(u"label")

        self.gridLayout_24.addWidget(self.label, 0, 0, 1, 1)

        self.connection_textbox_port = QLineEdit(self.groupBox_17)
        self.connection_textbox_port.setObjectName(u"connection_textbox_port")
        sizePolicy2.setHeightForWidth(self.connection_textbox_port.sizePolicy().hasHeightForWidth())
        self.connection_textbox_port.setSizePolicy(sizePolicy2)

        self.gridLayout_24.addWidget(self.connection_textbox_port, 1, 1, 1, 1)

        self.verticalSpacer_4 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_24.addItem(self.verticalSpacer_4, 9, 1, 1, 1)

        self.connection_btn_start = QPushButton(self.groupBox_17)
        self.connection_btn_start.setObjectName(u"connection_btn_start")
        sizePolicy1.setHeightForWidth(self.connection_btn_start.sizePolicy().hasHeightForWidth())
        self.connection_btn_start.setSizePolicy(sizePolicy1)

        self.gridLayout_24.addWidget(self.connection_btn_start, 3, 1, 1, 1)

        self.horizontalSpacer_2 = QSpacerItem(40, 20, QSizePolicy.Expanding, QSizePolicy.Minimum)

        self.gridLayout_24.addItem(self.horizontalSpacer_2, 9, 2, 1, 1)

        self.verticalSpacer_7 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Fixed)

        self.gridLayout_24.addItem(self.verticalSpacer_7, 2, 1, 1, 1)


        self.gridLayout_23.addLayout(self.gridLayout_24, 0, 0, 1, 1)


        self.gridLayout_21.addLayout(self.gridLayout_23, 0, 0, 1, 1)


        self.gridLayout_22.addWidget(self.groupBox_17, 0, 0, 1, 1)

        self.MainTabs.addTab(self.Settings, "")

        self.formLayout.setWidget(0, QFormLayout.SpanningRole, self.MainTabs)


        self.gridLayout_8.addLayout(self.formLayout, 0, 0, 1, 1)


        self.retranslateUi(GoldenBox_Form)

        self.MainTabs.setCurrentIndex(1)
        self.PeripheralTabs.setCurrentIndex(0)
        self.MainTabs_2.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(GoldenBox_Form)
    # setupUi

    def retranslateUi(self, GoldenBox_Form):
        GoldenBox_Form.setWindowTitle(QCoreApplication.translate("GoldenBox_Form", u"Golden Box", None))
        self.label_3.setText(QCoreApplication.translate("GoldenBox_Form", u"Welcome page", None))
        self.MainTabs.setTabText(self.MainTabs.indexOf(self.Welcome), QCoreApplication.translate("GoldenBox_Form", u"Welcome", None))
        self.DIGT_IN_CH_groupBox.setTitle(QCoreApplication.translate("GoldenBox_Form", u"DIGITAL INPUT CHANNEL", None))
        self.DIGT_IN_CH00_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 00", None))
        self.DIGT_IN_CH01_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 01", None))
        self.DIGT_IN_CH02_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 02", None))
        self.DIGT_IN_CH03_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 03", None))
        self.DIGT_IN_CH04_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 04", None))
        self.DIGT_IN_CH05_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 05", None))
        self.DIGT_IN_CH06_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 06", None))
        self.DIGT_IN_CH07_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital input 07", None))
        self.DIGT_OUT_CH_groupBox.setTitle(QCoreApplication.translate("GoldenBox_Form", u"DIGITAL OUTPUT CHANNEL", None))
        self.DIGT_OUT_CH08_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 08", None))
        self.DIGT_OUT_LOW_CH08_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH08_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH09_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 09", None))
        self.DIGT_OUT_LOW_CH09_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH09_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH10_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 10", None))
        self.DIGT_OUT_LOW_CH10_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH10_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH11_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 11", None))
        self.DIGT_OUT_LOW_CH11_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH11_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH12_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 12", None))
        self.DIGT_OUT_LOW_CH12_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH12_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH13_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 13", None))
        self.DIGT_OUT_LOW_CH13_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH13_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH14_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 14", None))
        self.DIGT_OUT_LOW_CH14_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH14_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.DIGT_OUT_CH15_GB.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Digital Output 15", None))
        self.DIGT_OUT_LOW_CH15_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"LOW", None))
        self.DIGT_OUT_HI_CH15_RB.setText(QCoreApplication.translate("GoldenBox_Form", u"HIGH", None))
        self.MainTabs_2.setTabText(self.MainTabs_2.indexOf(self.DIO), QCoreApplication.translate("GoldenBox_Form", u"DIO ", None))
        self.MainTabs_2.setTabText(self.MainTabs_2.indexOf(self.ADC), QCoreApplication.translate("GoldenBox_Form", u"ADC", None))
        self.MainTabs_2.setTabText(self.MainTabs_2.indexOf(self.tab), QCoreApplication.translate("GoldenBox_Form", u"Page", None))
        self.update_btn.setText(QCoreApplication.translate("GoldenBox_Form", u"Update", None))
        self.PeripheralTabs.setTabText(self.PeripheralTabs.indexOf(self.Main), QCoreApplication.translate("GoldenBox_Form", u"Main", None))
        self.PeripheralTabs.setTabText(self.PeripheralTabs.indexOf(self.communication), QCoreApplication.translate("GoldenBox_Form", u"communication", None))
        self.MainTabs.setTabText(self.MainTabs.indexOf(self.Peripherals), QCoreApplication.translate("GoldenBox_Form", u"Peripherals", None))
        self.groupBox_17.setTitle(QCoreApplication.translate("GoldenBox_Form", u"Network connection", None))
        self.connection_btn_stop.setText(QCoreApplication.translate("GoldenBox_Form", u"Stop", None))
        self.label_2.setText(QCoreApplication.translate("GoldenBox_Form", u"Port", None))
        self.connection_textbox_serverip.setInputMask("")
        self.connection_textbox_serverip.setPlaceholderText("")
        self.label.setText(QCoreApplication.translate("GoldenBox_Form", u"Server IP", None))
        self.connection_btn_start.setText(QCoreApplication.translate("GoldenBox_Form", u"Connect", None))
        self.MainTabs.setTabText(self.MainTabs.indexOf(self.Settings), QCoreApplication.translate("GoldenBox_Form", u"Settings", None))
    # retranslateUi

app = QApplication(sys.argv)
Widget = QWidget()
Form = Ui_GoldenBox_Form()
Form.setupUi(Widget)
Widget.show()
sys.exit(app.exec_())