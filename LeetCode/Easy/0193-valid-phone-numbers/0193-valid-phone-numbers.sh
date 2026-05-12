
valid_line() {
    local line="$1"
    if [[ "$line" =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$ ]]; then
        return 0
    elif [[ "$line" =~ ^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]]; then
        return 0
    fi
    return 1
}

while read -r line; do
    valid_line "$line" && echo "$line"
done < "file.txt"