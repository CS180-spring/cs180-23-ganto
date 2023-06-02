#include "../MyForm.h"
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    GantoGUI::MyForm form;
    Application::Run(% form);
}