#!/bin/bash

# aby nie wypisywac dziwnych rzeczy dla pustych katalogow z testami
shopt -s nullglob

# stworz tymczasowy katalog dla wynikow testow
RESULT_DIR=$(mktemp -d)

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;96m'
NO_COLOR='\033[0m'

if [ "${USE_VALGRIND}" = "1" ]
then
  VALGRIND="valgrind --leak-check=full -q"
else
  VALGRIND=""
fi

for TEST_IN_PATH in "${2}"/*.in
do
  TEST_FILE=$(basename ${TEST_IN_PATH})
  TEST_NAME=${TEST_FILE%.in}
  TEST_OUT_PATH="${RESULT_DIR}/${TEST_NAME}.out"
  TEST_ERR_PATH="${RESULT_DIR}/${TEST_NAME}.err"
  TEST_EXPECTED_OUT_PATH="${TEST_IN_PATH%.in}.out"
  TEST_EXPECTED_ERR_PATH="${TEST_IN_PATH%.in}.err"  

  echo -en "${YELLOW}Testing [${CYAN}${TEST_FILE}${YELLOW}]...${NO_COLOR} "

  < ${TEST_IN_PATH} "${1}" > ${TEST_OUT_PATH} 2> ${TEST_ERR_PATH}

  if [ "${VERBOSE}" = "1" ]
  then
        diff ${TEST_EXPECTED_OUT_PATH} ${TEST_OUT_PATH} \
          && diff ${TEST_EXPECTED_ERR_PATH} ${TEST_ERR_PATH} \
          && echo -e "${GREEN}PASSED${NO_COLOR}" \
          || echo -e "${RED}FAILED${NO_COLOR}"
  else
      diff ${TEST_EXPECTED_OUT_PATH} ${TEST_OUT_PATH} > /dev/null 2> /dev/null \
        && diff ${TEST_EXPECTED_ERR_PATH} ${TEST_ERR_PATH} > /dev/null 2> /dev/null \
        && echo -e "${GREEN}PASSED${NO_COLOR}" \
        || echo -e "${RED}FAILED${NO_COLOR}"
  fi
done
