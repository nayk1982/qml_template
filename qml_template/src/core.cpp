#include <QGuiApplication>
#include <QSettings>
#include <QDir>
#include <QUuid>

#include "AppCore"
#include "GuiAppCore"
#include "FileSys"
#include "core.h"
//==================================================================================================
using namespace file_sys;

//==================================================================================================
Core::Core(QObject *parent) : QObject(parent)
{
    initSettingsDirectory();
    loadMainSettings();
}
//==================================================================================================
QString Core::applicationVersion()
{
    return app_core::applicationVersion();
}
//==================================================================================================
QString Core::applicationBuildDate()
{
    return app_core::applicationBuildDate();
}
//==================================================================================================
QString Core::applicationTitle()
{
    return QGuiApplication::applicationDisplayName();
}
//==================================================================================================
QString Core::applicationOrganizationName()
{
    return QGuiApplication::organizationName();
}
//==================================================================================================
QString Core::applicationOrganizationDomain()
{
    return QGuiApplication::organizationDomain();
}
//==================================================================================================
QVariant Core::getSettingsValue(const QString &key, const QVariant &defaultValue) const
{
    QSettings settings(m_settingsDirName + m_settingsFileName, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    return settings.value(key, defaultValue);
}
//==================================================================================================
void Core::setSettingsValue(const QString &key, const QVariant &value) const
{
    QSettings settings(m_settingsDirName + m_settingsFileName, QSettings::IniFormat);
    settings.setIniCodec("UTF-8");
    settings.setValue(key, value);
    settings.sync();
}
//==================================================================================================
QString Core::getUuid() const
{
    return m_uuid;
}
//==================================================================================================
bool Core::getValue(const QString &key, bool defaultValue) const
{
    return getSettingsValue(key, QVariant(defaultValue)).toBool();
}
//==================================================================================================
void Core::setValue(const QString &key, bool value)
{
    setSettingsValue(key, QVariant(value));
}
//==================================================================================================
int Core::getValue(const QString &key, int defaultValue) const
{
    return getSettingsValue(key, QVariant(defaultValue)).toInt();
}
//==================================================================================================
void Core::setValue(const QString &key, int value)
{
    setSettingsValue(key, QVariant(value));
}
//==================================================================================================
QString Core::getValue(const QString &key, const QString &defaultValue) const
{
    return getSettingsValue(key, QVariant(defaultValue)).toString();
}
//==================================================================================================
void Core::setValue(const QString &key, const QString &value)
{
    setSettingsValue(key, QVariant(value));
}
//==================================================================================================
void Core::initSettingsDirectory()
{
    m_settingsDirName = app_core::applicationProfilePath();
    makePath( m_settingsDirName );
}
//==================================================================================================
void Core::loadMainSettings()
{
    m_uuid = getValue("app/uuid", QString(""));

    if(m_uuid.isEmpty()) {
        m_uuid = QUuid::createUuid().toString(QUuid::WithoutBraces);
        setValue("app/uuid", m_uuid);
    }
}
//==================================================================================================
