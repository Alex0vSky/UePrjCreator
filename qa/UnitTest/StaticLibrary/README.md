Putting It All Together.

NuGet package gmock disadvantages in portability area:
is difficult to use pch -- need change *.cc files;
for C++ builds is difficult to known *.h files location;
unable exclude from compilation files imported from gmock.targets.

clang options: -Wno-microsoft-enum-forward-reference -Wno-empty-body -Wno-microsoft-cast -Wno-microsoft-template 
googltest options: --gtest_break_on_failure
