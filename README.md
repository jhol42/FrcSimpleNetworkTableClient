
Simple network table client that connects to a local robot simulation's network table server.
Gets the 'LiveWindow/Ungrouped/DifferentialDrive[1]/Left Motor Speed' value using when running the gyro example.

Setup vcpkg
https://github.com/microsoft/vcpkg
```
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
.\vcpkg\bootstrap-vcpkg.bat
```

Integrate vcpgk with Visual Studio.  
From an administrator shell.
```
.\vcpkg\vcpkg integrate install
```

Install wpilib
.\vcpkg.exe install wpilib