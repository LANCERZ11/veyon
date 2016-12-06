/*
 * AccessControlPage.h - header for the AccessControlPage class
 *
 * Copyright (c) 2016 Tobias Doerffel <tobydox/at/users/dot/sf/dot/net>
 *
 * This file is part of iTALC - http://italc.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef ACCESS_CONTROL_PAGE_H
#define ACCESS_CONTROL_PAGE_H

#include <QStringListModel>

#include "ConfigurationPage.h"

namespace Ui {
class AccessControlPage;
}

class AccessControlPage : public ConfigurationPage
{
	Q_OBJECT

public:
	AccessControlPage();
	~AccessControlPage();

	virtual void resetWidgets();
	virtual void connectWidgetsToProperties();

private slots:
	void addAccessGroup();
	void removeAccessGroup();
	void updateAccessGroupsLists();

	void addAccessControlRule();
	void removeAccessControlRule();
	void editAccessControlRule();
	void moveAccessControlRuleDown();
	void moveAccessControlRuleUp();

	void testUserGroupsAccessControl();
	void testAccessControlRules();

private:
	void modifyAccessControlRules( const QStringList& accessControlRules, int selectedRow );
	void updateAccessControlRules();

	Ui::AccessControlPage *ui;

	QStringList m_accessGroups;
	QStringListModel m_accessControlRulesModel;

};

#endif // ACCESS_CONTROL_PAGE_H
