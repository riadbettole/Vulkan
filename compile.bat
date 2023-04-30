@echo off
for %%f in (*.vert *.frag) do (
  echo Compiling %%f...
  "C:\VulkanSDK\1.3.243.0\Bin\glslc.exe" "%%f" -o "%%~nf%%~xf.spv"
)
echo Done.
"C:\Users\riadb\source\repos\VulkanTest\x64\Debug\VulkanTest.exe"