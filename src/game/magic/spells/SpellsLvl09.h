/*
 * Copyright 2014 Arx Libertatis Team (see the AUTHORS file)
 *
 * This file is part of Arx Libertatis.
 *
 * Arx Libertatis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Arx Libertatis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Arx Libertatis.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ARX_GAME_MAGIC_SPELLS_SPELLSLVL09_H
#define ARX_GAME_MAGIC_SPELLS_SPELLSLVL09_H

#include "math/Types.h"

bool SummonCreatureSpellLaunch(long i, long duration);
void SummonCreatureSpellKill(long i);

bool FakeSummonSpellLaunch(long i);
void FakeSummonSpellKill(long i);

void LaunchAntiMagicField(size_t ident);
void NegateMagicSpellLaunch(long duration, long i);

bool IncinerateSpellLaunch(long i);

void MassParalyseSpellLaunch(long i, long duration);
void MassParalyseSpellKill();

#endif // ARX_GAME_MAGIC_SPELLS_SPELLSLVL09_H