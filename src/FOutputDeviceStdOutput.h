// src\FOutputDeviceStdOutput.h - ue serializer to console
#pragma once // Copyright 2023 Alex0vSky (https://github.com/Alex0vSky)
namespace prj_3d { namespace UePrjCreator {
class FOutputDeviceStdOutput : public FOutputDevice {
	ELogTimes::Type *m_pPrintLogTimes;
 public:
	explicit FOutputDeviceStdOutput(ELogTimes::Type *pPrintLogTimes) 
		: m_pPrintLogTimes( pPrintLogTimes )
    {}

	bool CanBeUsedOnAnyThread() const override {
		return true;
	}

	void Serialize( 
		const TCHAR* V
		, ELogVerbosity::Type Verbosity
		, const class FName& Category 
	) override {
		FString line = FOutputDeviceHelper::FormatLogLine(
			Verbosity, Category, V
			, *m_pPrintLogTimes
		);
		wprintf( TEXT("%s\n"), *line );
		fflush( stdout );
		return;
	}
};
}} // namespace prj_3d::UePrjCreator
