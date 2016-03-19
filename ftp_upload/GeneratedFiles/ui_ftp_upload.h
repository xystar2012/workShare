/********************************************************************************
** Form generated from reading UI file 'ftp_upload.ui'
**
** Created: Wed Jul 16 16:22:58 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FTP_UPLOAD_H
#define UI_FTP_UPLOAD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ftp_uploadClass
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QWidget *ftp_uploadClass)
    {
        if (ftp_uploadClass->objectName().isEmpty())
            ftp_uploadClass->setObjectName(QString::fromUtf8("ftp_uploadClass"));
        ftp_uploadClass->resize(735, 339);
        pushButton = new QPushButton(ftp_uploadClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 30, 81, 31));
        label = new QLabel(ftp_uploadClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 80, 541, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        textEdit = new QTextEdit(ftp_uploadClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(120, 150, 521, 141));

        retranslateUi(ftp_uploadClass);

        QMetaObject::connectSlotsByName(ftp_uploadClass);
    } // setupUi

    void retranslateUi(QWidget *ftp_uploadClass)
    {
        ftp_uploadClass->setWindowTitle(QApplication::translate("ftp_uploadClass", "ftp_upload", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ftp_uploadClass", "\344\270\212\344\274\240\345\222\214\344\270\213\350\275\275", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ftp_uploadClass", "\346\217\220\347\244\272\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ftp_uploadClass: public Ui_ftp_uploadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FTP_UPLOAD_H
