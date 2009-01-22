/*
 * This file is part of TelepathyQt4
 *
 * Copyright (C) 2008 Collabora Ltd. <http://www.collabora.co.uk/>
 * Copyright (C) 2008 Nokia Corporation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <TelepathyQt4/Client/OptionalInterfaceFactory>

#include "TelepathyQt4/debug-internal.h"

#include <QMap>
#include <QString>

namespace Telepathy
{
namespace Client
{

struct OptionalInterfaceFactory::Private
{
    QMap<QString, AbstractInterface*> interfaces;
};

OptionalInterfaceFactory::OptionalInterfaceFactory()
    : mPriv(new Private())
{
    debug() << "Constructing OptionalInterfaceFactory";
}

OptionalInterfaceFactory::~OptionalInterfaceFactory()
{
    debug() << "Destroying OptionalInterfaceFactory";

    for (QMap<QString, AbstractInterface *>::iterator i = mPriv->interfaces.begin();
            i != mPriv->interfaces.end();
            ++i) {
        debug().nospace() << " ~" << i.key();
        delete i.value();
    }

    delete mPriv;
}

AbstractInterface *OptionalInterfaceFactory::getCached(const QString &name) const
{
    if (mPriv->interfaces.contains(name)) {
        debug() << "Returning cached interface for" << name;
        return mPriv->interfaces.value(name);
    } else {
        debug() << "No interface found for" << name;
        return 0;
    }
}

void OptionalInterfaceFactory::cache(AbstractInterface *interface) const
{
    QString name = interface->interface();
    Q_ASSERT(!mPriv->interfaces.contains(name));

    debug() << "Caching interface" << name;
    mPriv->interfaces[name] = interface;
}

}
}
