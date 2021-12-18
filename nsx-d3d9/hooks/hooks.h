#include "../includes.h"
#include "menu/menu.h"

namespace hooks {
	inline long(__stdcall* o_present)(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);
	static std::once_flag m_initialized;

	inline long __stdcall present_hk(IDirect3DDevice9* device, const RECT* src_rect, const RECT* dest_rect, const HWND dest_window, const RGNDATA* dirty_region) {
		render::m_pDevice = device;

		render::SaveDeviceStates();

		std::call_once(m_initialized, [&]() {
			menu::initialize();
		});

		menu::render();

		render::RestoreDeviceStates();

		return o_present(device, src_rect, dest_rect, dest_window, dirty_region);
	}
	
	inline void initialize() {
		bool attached = false;
		do {
			if (kiero::init(kiero::RenderType::D3D9) == kiero::Status::Success) {
				kiero::bind(17, reinterpret_cast<void**>(&o_present), present_hk);

				attached = true;
			}
		} while (!attached);
	}
}