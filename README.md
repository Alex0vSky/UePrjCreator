# _UePrjCreator_
[![WindowsOs-logo](https://img.shields.io/badge/platform-windows-blue?logo=Windows)](
https://en.wikipedia.org/wiki/Microsoft_Windows
) [![cpp-logo](https://img.shields.io/badge/C%2B%2B-v17-blue?logo=cplusplus)](
https://en.wikipedia.org/wiki/C++
) [![UnrealEngine-logo](https://img.shields.io/badge/UnrealEngine-4-blue?logo=unrealengine)](
https://en.wikipedia.org/wiki/UnrealEngine
)

[![Qa test and coverage](https://github.com/Alex0vSky/UePrjCreator/actions/workflows/qa-UnitTest-Coverage.yml/badge.svg)](
https://github.com/Alex0vSky/UePrjCreator/actions/workflows/qa-UnitTest-Coverage.yml
)

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

Tool for create __Unreal Engine__ _*.uproject_ file and directory structure from command line. From ***scratch*** or from template. 
<br/>***Not only*** VS project files. ***Not only*** UnrealEngine project files for your IDE. 
<br/>It completely repeats the behavior of UnrealEngine when creating a new project through the _"Project Explorer"_ without a long full load of the engine.
## Features
The resulting directory containing the _*.uproject_ file is ready to be built into an executable via UnrealEngine UBT. Can use UnrealEngine templates. If the template contains C++ classes, IDE project files will be generated. The tool contains an internal template for building an executable file without building _*Editor.dll_ library.
<br/><sub>Under the hood, the tool loads the Unreal core, performs minimal initialization, and calls the core functionality.</sub>
## Requirements
Requires installed Unreal Engine version 4.
## Install
The tool consists of one file. Does not require installation. 
## Usage
For example, the desired fully qualified filename for the _*.uproject_ location would be `C:\UePrj1\UePrj1.uproject`
<br/><sub>For the term _UnrealEngine_, the abbreviation _Ue_ will be used below.</sub>
* Generate a standart blank project
  - Easy start for the latest version of the installed _Ue_:
  <br/>`UePrjCreator "C:\UePrj1\UePrj1.uproject"`
  - Run for a specific installed version of the _Ue_:
  <br/>`UePrjCreator "C:\UePrj1\UePrj1.uproject" --UeVersion=4.26`
  - Run for installed _Ue_ in certain path in quotes:
  <br/>`UePrjCreator "C:\UePrj1\UePrj1.uproject" --UeInstallDir="C:\Program Files\Epic Games\UE_4.26"`
* Generate from an existing template with a quoted path for a specific installed version of _Ue_:
  <br/>`UePrjCreator "C:\UePrj1\UePrj1.uproject" --UeVersion=4.26 --Tpl="C:\Program Files\Epic Games\UE_4.26\Templates\TP_SideScroller\TP_SideScroller.uproject"`
* Generate for a game with one executable, without _*Engine.dll_, for a specific installed version of _Ue_:
  <br/>`UePrjCreator "C:\UePrj1\UePrj1.uproject" --UeVersion=4.26 --DevTpl`

More options:
- Settings for _*\%yourProjectName%\Config\DefaultEngine.ini_ section [/Script/HardwareTargeting.HardwareTargetingSettings]
> ```
> --TargetedHardwareClass=<value> [Unspecified, Maximum, Scalable>, default: Scalable]
> --DefaultGraphicsPerformance=<value> [Unspecified, Desktop, Mobile>, default: Desktop]
> ```
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
+ Inspired by video [Unreal Engine C++ Project Setup, From Scratch](https://www.youtube.com/watch?v=94FvzO1HVzY) of youtube blogger __Alex Forsythe__ ([GitHubUser](https://github.com/awforsythe), [More](http://awforsythe.com)).
+ [morrisfranken/argparse](https://github.com/morrisfranken/argparse)
+ [Neargye/magic_enum](https://github.com/Neargye/magic_enum)
+ googletest+googlemock [google/googletest](https://github.com/google/googletest)
+ vs_google_test_explorer_namespace.h [Macro to Enable Namespaces in Google Test Adapter for Visual Studio](https://bitbucket.org/CadActive/workspace/snippets/GrBakB/macro-to-enable-namespaces-in-google-test) by James Sullivan ([More](https://developercommunity.visualstudio.com/t/test-explorer-namespace-seems-to-not-be-working/663974))
## License
See the [LICENSE](https://github.com/Alex0vSky/UePrjCreator/blob/main/LICENSE) file for license rights and limitations (MIT).
