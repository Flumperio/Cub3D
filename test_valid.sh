RED='\033[0;31m'
NC='\033[0m'
for file in /Users/juasanto/Desktop/Cub3D/maps/validos/*
do
echo "${RED}$file${NC}"
./cub3D "$file"
echo "\n"
done
