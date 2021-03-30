RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
for file in ./maps/novalidos/*
do
echo "${RED}$file${NC}"
echo "${GREEN}MAP"
cat "$file"
echo "\033[0m\n"
./cub3D "$file"

done
