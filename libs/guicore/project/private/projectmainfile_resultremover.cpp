#include "projectmainfile_resultremover.h"

#include <cgnslib.h>

#include <string>
#include <vector>

namespace  {

const int NAME_MAXLEN = 32;
const std::string BINAME = "BaseIterativeData";
const std::string ZINAME = "ZoneIterativeData";

void gotoBase(int fn, int B)
{
	cg_goto(fn, B, NULL);
}

void gotoZone(int fn, int B, int Z)
{
	cg_goto(fn, B, "Zone_t", Z, NULL);
}

void deleteBaseIterativeData(int fn, int B)
{
	gotoBase(fn, B);
	cg_delete_node(BINAME.c_str());
}

void deleteZoneIterativeData(int fn, int B, int Z)
{
	gotoZone(fn, B, Z);
	cg_delete_node(ZINAME.c_str());
}

void deleteSolutions(int fn, int B, int Z)
{
	int numSols;
	cg_nsols(fn, B, Z, &numSols);

	gotoZone(fn, B, Z);
	for (int S = numSols; S >= 1; --S) {
		char name[NAME_MAXLEN];
		GridLocation_t location;

		cg_sol_info(fn, B, Z, S, name, &location);
		cg_delete_node(name);
	}
}

void deleteParticleSolutions(int fn, int B, int Z)
{
	gotoZone(fn, B, Z);

	int numUsers;
	cg_nuser_data(&numUsers);

	for (int U = numUsers; U >= 1; --U) {
		char name[NAME_MAXLEN];
		cg_user_data_read(U, name);
		if (strncmp(name, "ParticleSolution", 16) == 0) {
			cg_delete_node(name);
		}
	}
}

void deleteResultGrids(int fn, int B, int Z)
{
	int numGrids;
	cg_ngrids(fn, B, Z, &numGrids);

	gotoZone(fn, B, Z);
	for (int G = numGrids; G >= 2; --G) {
		char name[NAME_MAXLEN];
		cg_grid_read(fn, B, Z, G, name);
		cg_delete_node(name);
	}
}

} // namespace

void ProjectMainFile::ResultRemover::removeResults(int fn)
{
	int ier;
	int numBases;
	ier = cg_nbases(fn, &numBases);

	for (int B = 1; B <= numBases; ++B) {
		deleteBaseIterativeData(fn, B);
		int numZones;
		ier = cg_nzones(fn, B, &numZones);

		for (int Z = 1; Z <= numZones; ++Z) {
			deleteZoneIterativeData(fn, B, Z);
			deleteSolutions(fn, B, Z);
			deleteParticleSolutions(fn, B, Z);
			deleteResultGrids(fn, B, Z);
		}
	}
}
