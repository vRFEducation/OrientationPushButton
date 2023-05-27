#include "OrinetationPushButton.h"
#include "OrinetationPushButtonPlugin.h"

#include <QtPlugin>

OrinetationPushButtonPlugin::OrinetationPushButtonPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void OrinetationPushButtonPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool OrinetationPushButtonPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *OrinetationPushButtonPlugin::createWidget(QWidget *parent)
{
    return new OrinetationPushButton(parent);
}

QString OrinetationPushButtonPlugin::name() const
{
    return QLatin1String("OrinetationPushButton");
}

QString OrinetationPushButtonPlugin::group() const
{
    return QLatin1String("Custom Buttons");
}

QIcon OrinetationPushButtonPlugin::icon() const
{
    return QIcon();
}

QString OrinetationPushButtonPlugin::toolTip() const
{
    return QLatin1String("A button which can change orientation");
}

QString OrinetationPushButtonPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool OrinetationPushButtonPlugin::isContainer() const
{
    return false;
}

QString OrinetationPushButtonPlugin::domXml() const
{
    return QLatin1String("<widget class=\"OrinetationPushButton\" name=\"orinetationPushButton\">\n</widget>\n");
}

QString OrinetationPushButtonPlugin::includeFile() const
{
    return QLatin1String("OrinetationPushButton.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(OrinetationPushButtonPlugin, OrinetationPushButtonPlugin)
#endif // QT_VERSION < 0x050000
