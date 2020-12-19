#ifndef TERMINAL_UI_H
#define TERMINAL_UI_H

#include <iostream>
#include <fstream>
#include <string>

#include "../headers/accountant.h"
#include "../headers/company.h"
#include "../headers/departments.h"
#include "../headers/employee.h"
#include "../headers/person.h"
#include "../headers/title.h"
#include "../headers/database.h"
#include "../headers/it.h"
#include "../headers/purchasing.h"
#include "../headers/advertisement.h"
#include "../headers/public_relations.h"
#include "../headers/human_res.h"

void ui();
void depPage(Departments *dep);

void showDepEmployees(Departments *dep);
void addEmployee(Departments *dep);

#endif