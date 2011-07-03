/*****************************************************************************
 * PokerTH - The open source texas holdem engine                             *
 * Copyright (C) 2006-2011 Felix Hammer, Florian Thauer, Lothar May          *
 *                                                                           *
 * This program is free software: you can redistribute it and/or modify      *
 * it under the terms of the GNU Affero General Public License as            *
 * published by the Free Software Foundation, either version 3 of the        *
 * License, or (at your option) any later version.                           *
 *                                                                           *
 * This program is distributed in the hope that it will be useful,           *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
 * GNU Affero General Public License for more details.                       *
 *                                                                           *
 * You should have received a copy of the GNU Affero General Public License  *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.     *
 *****************************************************************************/
#include "timeoutmsgboximpl.h"
#include "session.h"

timeoutMsgBoxImpl::timeoutMsgBoxImpl(QMainWindow *parent)
	: QMessageBox(parent), msgID(NETWORK_TIMEOUT_GENERIC)
{
	okButton = this->addButton(QMessageBox::Ok);

	this->setWindowTitle(tr("Timeout Warning"));
	this->setIcon(QMessageBox::Warning);
	this->setInformativeText(tr("Please click \"OK\" to stop the countdown!"));

	timeOutTimer = new QTimer;

	connect(timeOutTimer, SIGNAL(timeout()), this, SLOT(timerRefresh()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(stopTimeout()));

}

timeoutMsgBoxImpl::~timeoutMsgBoxImpl()
{
}

void timeoutMsgBoxImpl::startTimeout()
{
	//start the real timer
	realTimer.reset();
	realTimer.start();
	timerRefresh();
	timeOutTimer->start(1000);
}

void timeoutMsgBoxImpl::timerRefresh()
{

	int sec = timeoutDuration;
	unsigned int realTimerValue = realTimer.elapsed().total_milliseconds();
	sec -= realTimerValue/1000;
	if (sec < 0) sec = 0;
	switch (msgID) {
	case NETWORK_TIMEOUT_GAME_ADMIN_IDLE:
		this->setText(tr("You are game-admin of an open game which will time out in %1 seconds.").arg(sec,0,10));
		break;
	default:
		this->setText(tr("Your connection is about to time out due to inactivity in %1 seconds.").arg(sec,0,10));
		break;
	}
}

void timeoutMsgBoxImpl::stopTimeout()
{

	mySession->resetNetworkTimeout();
}
