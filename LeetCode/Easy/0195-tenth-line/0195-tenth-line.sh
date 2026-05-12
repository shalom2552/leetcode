# Read from the file file.txt and output the tenth line to stdout.

if [[ $(wc -l file.txt | cut -d ' ' -f1) -lt 10 ]]; then
    echo
    exit 1
fi

sed -n '10p' file.txt