// src\DelayloadStaticVar.h - when dll is Delayload, static variable cannot be referenced directly
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator { namespace DelayloadStaticVar {
struct GetAddressBySymbol { 
	class ScopedFree { 
		HMODULE m_h;
	public:
		explicit ScopedFree(HMODULE h) : m_h( h )
		{}
		~ScopedFree()
		{ if ( m_h ) ::FreeLibrary( m_h ); }
	};
	static bool UE4Editor_Core( 
		ELogTimes::Type *&pGPrintLogTimes
		, FOutputDeviceError **&pGError
		, FFeedbackContext **&pGWarn
		, FSimpleMulticastDelegate *&pOnInit
	) {
		FARPROC p;
		HMODULE h = ::LoadLibraryA( "UE4Editor-Core.dll" );
		if ( !h )
			return false;
		ScopedFree anon( h );

		// origin Engine\Source\Editor\HardwareTargeting\Public\HardwareTargetingSettings.h
		p = ::GetProcAddress( h, "?GPrintLogTimes@@3W4Type@ELogTimes@@A" );
		if ( !p )
			return false;
		pGPrintLogTimes = reinterpret_cast<ELogTimes::Type *>( p );

		// origin Engine\Source\Runtime\Core\Public\CoreFwd.h
		p = ::GetProcAddress( h, "?GWarn@@3PEAVFFeedbackContext@@EA" );
		if ( !p )
			return false;
		pGWarn = reinterpret_cast<FFeedbackContext **>( p );

		p = ::GetProcAddress( h, "?GError@@3PEAVFOutputDeviceError@@EA" );
		if ( !p )
			return false;
		pGError = reinterpret_cast<FOutputDeviceError **>( p );

		// origin Engine\Source\Runtime\Core\Public\Delegates\Delegate.h
		// origin Engine\Source\Runtime\Core\Public\Misc\CoreDelegates.h
		// call for example Broadcast( ) look like FCoreDelegates::OnInit.Broadcast( )
		p = ::GetProcAddress( h, 
"?OnInit@FCoreDelegates@@2V?$TMulticastDelegate@$$A6AXXZUFDefaultDelegateUserPolicy@@@@A" );
		if ( !p )
			return false;
		pOnInit = reinterpret_cast<FSimpleMulticastDelegate *>( p );

		return true;
	}
};
}}} // namespace prj_3d::UePrjCreator::DelayloadStaticVar
