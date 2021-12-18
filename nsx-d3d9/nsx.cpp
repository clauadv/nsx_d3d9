#include "includes.h"

void nsx(void* arg) {
	try {
		input_win32::OnEntryPoint();
		render::OnEntryPoint();
		hooks::initialize();
	} catch (const std::runtime_error& error) {
		MessageBoxA(nullptr, error.what(), "nsx-d3d9 error!", MB_OK | MB_ICONERROR);
		FreeLibraryAndExitThread(static_cast<HMODULE>(arg), 0);
	}
}

bool DllMain(const HMODULE module [[maybe_unused]], const std::uint32_t call_reason, void* reserved [[maybe_unused]]) {
	if (call_reason != DLL_PROCESS_ATTACH)
		return false;

	native_thread<nsx>().run(nullptr);

	return true;
}