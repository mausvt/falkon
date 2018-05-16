/* ============================================================
* Falkon - Qt web browser
* Copyright (C) 2018 Anmol Gautam <tarptaeya@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#include "qmlpluginloader.h"

QmlPluginLoader::QmlPluginLoader(const QString &path)
{
    m_engine = new QQmlEngine();
    m_component = new QQmlComponent(m_engine, path);
    createComponent();
}

void QmlPluginLoader::createComponent()
{
    m_interface = qobject_cast<QmlPluginInterface*>(m_component->create());
}

void QmlPluginLoader::setName(const QString &name)
{
    if (!m_interface) {
        return;
    }

    m_interface->setName(name);
}

QQmlComponent *QmlPluginLoader::component() const
{
    return m_component;
}

QmlPluginInterface *QmlPluginLoader::instance() const
{
    return m_interface;
}