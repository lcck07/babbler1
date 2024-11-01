#include "babbler1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
babbler1App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babbler1App::babbler1App(InputParameters parameters) : MooseApp(parameters)
{
  babbler1App::registerAll(_factory, _action_factory, _syntax);
}

babbler1App::~babbler1App() {}

void
babbler1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<babbler1App>(f, af, s);
  Registry::registerObjectsTo(f, {"babbler1App"});
  Registry::registerActionsTo(af, {"babbler1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
babbler1App::registerApps()
{
  registerApp(babbler1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
babbler1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babbler1App::registerAll(f, af, s);
}
extern "C" void
babbler1App__registerApps()
{
  babbler1App::registerApps();
}
