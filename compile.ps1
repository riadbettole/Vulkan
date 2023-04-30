Write-Host "HEEEELLO RYAD"
$files = Get-ChildItem -Path . | Where-Object {$_.Extension -eq '.vert' -or $_.Extension -eq '.frag'}

$files | ForEach-Object {
    $inputFile = $_.FullName
    $outputFile = "$($_.BaseName)$($_.Extension).spv"
    & "C:\VulkanSDK\1.3.243.0\Bin\glslc.exe" $inputFile -o $outputFile
    if (Test-Path $outputFile) {
        Write-Host "Compiled $inputFile to $outputFile"
    } else {
        Write-Warning "Failed to compile $inputFile"
    }
}