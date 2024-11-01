//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "babbler1TestApp.h"
#include "babbler1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
babbler1TestApp::validParams()
{
  InputParameters params = babbler1App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babbler1TestApp::babbler1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  babbler1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

babbler1TestApp::~babbler1TestApp() {}

void
babbler1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  babbler1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"babbler1TestApp"});
    Registry::registerActionsTo(af, {"babbler1TestApp"});
  }
}

void
babbler1TestApp::registerApps()
{
  registerApp(babbler1App);
  registerApp(babbler1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
babbler1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babbler1TestApp::registerAll(f, af, s);
}
extern "C" void
babbler1TestApp__registerApps()
{
  babbler1TestApp::registerApps();
}
