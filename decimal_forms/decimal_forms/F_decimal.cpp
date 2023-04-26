#include "F_decimal.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace decimalforms;
[STAThread]
int main(array<System::String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew F_decimal());
}