/****************************************************************************
** Copyright (c) 2019 Evgeny Teterin (nayk) <sutcedortal@gmail.com>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/
#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QVariant>

//==================================================================================================
class Core : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString applicationVersion READ applicationVersion CONSTANT)
    Q_PROPERTY(QString applicationBuildDate READ applicationBuildDate CONSTANT)
    Q_PROPERTY(QString applicationTitle READ applicationTitle CONSTANT)
    Q_PROPERTY(QString applicationOrganizationName READ applicationOrganizationName CONSTANT)
    Q_PROPERTY(QString applicationOrganizationDomain READ applicationOrganizationDomain CONSTANT)
    Q_PROPERTY(QString applicationUuid READ getUuid CONSTANT)

public:
    explicit Core(QObject *parent = nullptr);
    static QString applicationVersion();
    static QString applicationBuildDate();
    static QString applicationTitle();
    static QString applicationOrganizationName();
    static QString applicationOrganizationDomain();

    QVariant getSettingsValue(const QString &key, const QVariant &defaultValue) const;
    void setSettingsValue(const QString &key, const QVariant &value) const;
    QString getUuid() const;

    Q_INVOKABLE bool getValue(const QString &key, bool defaultValue) const;
    Q_INVOKABLE void setValue(const QString &key, bool value);
    Q_INVOKABLE int getValue(const QString &key, int defaultValue) const;
    Q_INVOKABLE void setValue(const QString &key, int value);
    Q_INVOKABLE QString getValue(const QString &key, const QString &defaultValue) const;
    Q_INVOKABLE void setValue(const QString &key, const QString &value);

private:
    const QString m_settingsFileName { "settings.conf" };
    QString m_settingsDirName { "" };
    QString m_uuid { "" };
    //
    void initSettingsDirectory();
    void loadMainSettings();
};
//==================================================================================================
#endif // CORE_H
