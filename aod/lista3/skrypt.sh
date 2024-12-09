
#!/bin/bash

if [ -z "$1" ]; then
    echo "Użycie: $0 <ścieżka>"
    exit 1
fi


directory_path="$1"


if [ ! -d "$directory_path" ]; then
    echo "Podana ścieżka '$directory_path' nie istnieje lub nie jest katalogiem."
    exit 1
fi

make

find "$directory_path" -type f -name "*.gr" | while read -r file; do

    echo "Przetwarzam plik: $file"
    ./program $file

done
