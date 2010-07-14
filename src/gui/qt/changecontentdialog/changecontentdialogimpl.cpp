/***************************************************************************
 *   Copyright (C) 2006 by FThauer FHammer   *
 *   f.thauer@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "changecontentdialogimpl.h"
// #include "session.h"
#include "configfile.h"

changeContentDialogImpl::changeContentDialogImpl(QWidget *parent, ConfigFile *config)
      : QDialog(parent), myConfig(config)
{
#ifdef __APPLE__
	setWindowModality(Qt::ApplicationModal);
	setWindowFlags(Qt::WindowSystemMenuHint | Qt::CustomizeWindowHint | Qt::Dialog);
#endif	
    	setupUi(this);

	lineEdit->setText(QString::fromUtf8(myConfig->readConfigString("MyName").c_str()));

	connect(this, SIGNAL(accepted ()), this, SLOT(savePlayerName()));

}

void changeContentDialogImpl::saveContent() {

	myConfig->writeConfigString("MyName", lineEdit->text().toUtf8().constData());
	//write buffer to disc 
	myConfig->writeBuffer();
}