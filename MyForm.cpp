#include "MyForm.h"

void main() {
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(true);
	GraphicEngine::MyForm form;
	System::Windows::Forms::Application::Run(% form);
}