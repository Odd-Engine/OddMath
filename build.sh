#!/bin/bash

if [ -n $VIRTUAL_ENV ]
then
    deactivate
fi

for i in "$@"; do
  case $i in
    --no-venv=*)
      NOVENV="${i#*=}"
      shift # past argument=value
      ;;
    --coverage=*)
      COVERAGE="${i#*=}"
      shift # past argument=value
      ;;
    --run-tests=*)
      RUN_TESTS="${i#*=}"
      shift # past argument=value
      ;;
    -*|--*)
      echo "Unknown option $i"
      exit 1
      ;;
    *)
      ;;
  esac
done

ROOT=$(dirname "$(realpath $0)")
BUILD=${ROOT}/build

cd ${ROOT}

if [ -z $NOVENV ]
then
    PYTHON=$(find * | grep -i "bin/python\$")
    if [ -z ${PYTHON} ]
    then
        echo "No venv detected, creating one with default python3 installation"
        python3 -m venv venv
        VENV="venv/bin"
    else
        VENV=$(echo $(dirname $PYTHON))
        echo "Using existing virtual environment located at "$(dirname ${VENV})
    fi

    source ${VENV}/activate
    pip install -r ${ROOT}/requirements.txt
else
    echo "Installing to user global python3 install"
    pip3 install -r ${ROOT}/requirements.txt --user
fi

if [ -n $COVERAGE ]
then
    meson setup ${BUILD} -Dcoverage=true
else
    meson setup ${BUILD}
fi
cd ${BUILD}
meson compile

if [ -n $RUN_TESTS ]
then
    meson compile test_suite
    ${BUILD}/test_suite
fi

if [ -n $NOVENV ]
then
    deactivate
fi
