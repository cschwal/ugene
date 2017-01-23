/**
 * UGENE - Integrated Bioinformatics Tools.
 * Copyright (C) 2008-2016 UniPro <ugene@unipro.ru>
 * http://ugene.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */

#include "WebWindow.h"
#include <QtWidgets/QVBoxLayout>

#include <QtWebEngineWidgets/QWebEngineView>

namespace U2 {

WebWindow::WebWindow(const QString& title, const QString& content)
: MWMDIWindow(title)
{
    QVBoxLayout* l = new QVBoxLayout();
    l->setMargin(0);
    setLayout(l);

    QWebEngineView* textEdit = new QWebEngineView(this);
    textEdit->setContextMenuPolicy(Qt::NoContextMenu);
    textEdit->setHtml(content);

    l->addWidget(textEdit);
}

} //namespace
