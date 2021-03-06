#ifndef WMV_LISTS_H
#define WMV_LISTS_H

// This is used for various lists and other static variables.

#include <QString>
#include <QList>
#include <QMap>
#include "version.h"
#include "constants.h"
#include "classes.h"

// Locale List
// Placement matches WoWLocale number
static QList<QString> LocaleList = QList<QString>()
	<< "enUS"		// English, US
	<< "enGB"		// English, Great Britian
	<< "frFR"		// French
	<< "deDE"		// German
	<< "koKR"		// Korean
	<< "zhCN"		// Chinese, Simplified
	<< "zhTW"		// Chinese, Traditional
	<< "esES"		// Spanish, Spain
	<< "esMX"		// Spanish, Mexico
	<< "ruRU"		// Russian
	<< "jaJP"		// Japanese
	<< "ptBR"		// Portuguese, Brazil
	<< "itIT"		// Italian
	<< "plPL"		// Polish

	<< "None";		// Used for Error Detection. Should ALWAYS be last!

// Expansion Name List
static QList<QString> ExpansionNameList = QList<QString>()
	<< QObject::tr("Vanilla")
	<< QObject::tr("Burning Crusade")
	<< QObject::tr("Wrath of the Lich King")
	<< QObject::tr("Cataclysm")
	<< QObject::tr("Mists of Pandaria")
	
	<< QObject::tr("Public Test Realm")
	<< QObject::tr("Beta Server");


// --== Static Global Variables ==--

// Our master list of currently loaded MPQ archives
static t_ArchiveSet LoadedArchives;

// A list to temporaily store an MPQ list.
static t_ArchiveSet TempArchiveList;

#endif