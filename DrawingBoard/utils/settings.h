/*
   Drawpile - a collaborative drawing program.

   Copyright (C) 2015 Calle Laakkonen

   Drawpile is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Drawpile is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Drawpile.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SETTINGS_H
#define SETTINGS_H

class QString;
class QStringList;

namespace utils {
namespace settings {

/**
 * @brief Get the path where to put recordings
 *
 * Return the value of settings/recording/folder
 * or a built-in default if it does not exist
 */
//QString recordingFolder();

/**
 * @brief Get a list of paths in which datafiles may reside
 */
QStringList dataPaths();

}
}

#endif
