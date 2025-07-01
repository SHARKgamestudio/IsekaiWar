#include "Managers.h"

#ifdef _DEBUG
int main() {
	srand(time(NULL));
	Managers::GetInstance()->GameManager->Run();
	delete Managers::GetInstance();
	return 0;
}
#else
#include <Windows.h>
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	srand(time(NULL));
	Managers::GetInstance()->GameManager->Run();
	delete Managers::GetInstance();
	return 0;
}
#endif