# UserPromptSubmit 훅 스크립트
# stdin으로 들어오는 JSON에서 prompt를 추출하여 history.prompt.txt에 저장

# stdin을 UTF-8로 읽어 한글 깨짐 방지
[Console]::InputEncoding  = [System.Text.Encoding]::UTF8
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8

$data    = [Console]::In.ReadToEnd() | ConvertFrom-Json
$prompt  = $data.prompt

if (-not $prompt) { exit 0 }

$filePath = "history.prompt.txt"
$content  = if (Test-Path $filePath) { Get-Content -LiteralPath $filePath -Encoding UTF8 } else { @() }

# 현재 가장 큰 번호 찾기 (없으면 0)
$maxNum = 0
foreach ($line in $content) {
    if ($line -match '^(\d+)\s') {
        $n = [int]$Matches[1]
        if ($n -gt $maxNum) { $maxNum = $n }
    }
}
$num = $maxNum + 1

# 새 항목을 맨 앞에 추가 (빈 줄 포함)
$newContent = @("$num $prompt", '') + $content
Set-Content -LiteralPath $filePath -Value $newContent -Encoding UTF8
