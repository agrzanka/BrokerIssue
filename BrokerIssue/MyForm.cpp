#include "MyForm.h"

//using namespace FtoC;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int Main(/*array<System::String ^> ^args*/)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	BrokerIssue::MyForm form;
	Application::Run(%form);
	return 0;
}