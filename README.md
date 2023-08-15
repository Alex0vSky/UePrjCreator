# _UePrjCreator_
[![windows-os](https://img.shields.io/badge/platform-windows-blue?logo=Windows)](
https://en.wikipedia.org/wiki/Microsoft_Windows
) [![cpp-logo](https://img.shields.io/badge/C%2B%2B-v17-blue?logo=cplusplus)](
https://en.wikipedia.org/wiki/C++
)

[![Qa test and coverage](https://github.com/Alex0vSky/UePrjCreator/actions/workflows/qa-UnitTest-Coverage.yml/badge.svg)](https://github.com/Alex0vSky/UePrjCreator/actions/workflows/qa-UnitTest-Coverage.yml)
[![cpplint](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/GoogleStyle_cpplint.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/cpplint.xml
) [![cppcheck](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/StaticAnalysis_cppcheck.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/cppcheck.xml
) [![LinesOfСode](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/Metrixpp-LinesOfСode.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/metrixpp.txt
) [![Comments](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/Metrixpp-Comments.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/metrixpp.txt
) [![amount testsuites](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/GoogleTest-testsuites-Windows-x64-Debug.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/GoogleTestCombinedOutput/index.html
) [![tests coverage](https://gist.githubusercontent.com/Alex0vSky/c200bc8d7e3cc3a79b61351963b2d390/raw/TestsCoverage-Occ-Windows-x64-Debug.svg)](
https://Alex0vSky.github.io/project-qa-report/UePrjCreator/HtmlReportOcc/index.html
)

Tool for generate __Unreal Engine__ *.uproject files and directory structure with required C++ classes from command line by template.
The resulting directory containing the *.uproject file is ready to be embedded into an executable via UnrealEngine UBT.
The tool contains a template for building an executable file without creating *Editor.dll library.

## Features

## Requirements
Requires installed Unreal Engine version 4.

## Install
The tool consists of one file. Does not require installation. 

## Usage
For the term UnrealEngine, the abbreviation Ue will be used below.

First set desired full file name for *.uproject location
set ffnUprj=C:\Prj\Ue\FromUePrjCreator\FromUePrjCreator.uproject

Generate standart blank project
Simple run for higher/major installed Ue version
UePrjCreator.exe %ffnUprj%
Run for certain installed Ue version
UePrjCreator.exe %ffnUprj% --UeVersion=4.26
Run for installed Ue in certain path in quotes
UePrjCreator.exe %ffnUprj% --UeInstallDir="C:\Program Files\Epic Games\UE_4.26"

Generate single exe game, without *Engine.dll/%yourProjectName%Engine.dll, for certain installed Ue version
UePrjCreator.exe %ffnUprj% --UeVersion=4.26 --DevTpl

Generate from exists template by path in quotes, for certain installed Ue version
UePrjCreator.exe %ffnUprj% --UeVersion=4.26 --Tpl="C:\Program Files\Epic Games\UE_4.26\Templates\TP_SideScroller"

More options:
Settings for *\%yourProjectName%\Config\DefaultEngine.ini section [/Script/HardwareTargeting.HardwareTargetingSettings]
--TargetedHardwareClass=<value>
--DefaultGraphicsPerformance=<value>

## Tests
### CI github actions
+ qa UnitTest and coverage: _google-test_, _OpenCppCoverage/OpenCppCoverage_;
+ qa staticAnalysis and codeMetrics: _cppcheck_, py _metrixpp_, py _cpplint_;
+ auxiliary: py _junitparser_, py _burlachenkok/gtest_report_(fork).

## Build
Building the project and tests from the source code requires the presence of the __Microsoft Visual Studio 2019 Community__, and using *.sln and *.vcxproj project files. The project is also ready to be built via __clang__ version __12.0.0__, which comes with __VIsualStudioCommunity2019__.

## Contributing
Can ask questions. PRs are accepted. No requirements for contributing.

## Thanks
Inspired by youtube blogger

_morrisfranken/argparse_
_Neargye/magic_enum_

## License
See the [LICENSE](https://github.com/Alex0vSky/UePrjCreator/blob/main/LICENSE) file for license rights and limitations (MIT).
