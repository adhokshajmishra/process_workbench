/*
 * Process Analyzer is a small tool to analyze processes on standard LINUX
 * platform.
 *
 * Copyright (c) Adhokshaj Mishra, Swen Kooij
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
 */

/*
 * Author: Adhokshaj Mishra
 *
 * This header file contains error codes in form of #defines.
 * These error codes are supposed to be returned from internal functions.
 *
 * #defines are used to avoid magic numbers.
 */

#ifndef ERROR_CODES_H
#define ERROR_CODES_H

#define ERROR_SUCESS 0

// File I/O errors
#define ERROR_FILE_NOT_OPENED 10

#endif // ERROR_CODES_H
