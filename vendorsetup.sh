CLANGDIR=$PWD/prebuilts/clang/host/linux-x86
if [ ! -d "${CLANGDIR}/clang-r487747" ]
then
    GREEN='\033[0;32m'
    NC='\033[0m'
    echo -e "${GREEN}Downloading clang 17.0.0${NC}"
    mkdir ${CLANGDIR}/clang-r487747
    wget https://android.googlesource.com/platform/prebuilts/clang/host/linux-x86/+archive/refs/heads/master/clang-r487747.tar.gz -P ${CLANGDIR}
    tar -C "${CLANGDIR}"/clang-r487747/ -zxf "${CLANGDIR}"/clang-r487747.tar.gz
    rm ${CLANGDIR}/clang-r487747.tar.gz
fi