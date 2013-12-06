#/bin/bash


# Check the arguments

E_BADARGS=65
_num=1

if [ $# -eq 1 ]; then
  if ! [[ "$1" =~ ^[0-9]+$ ]]; then
    echo "Error: Passed argument is not an integer value."
    exit $E_BADARGS
  fi
  _num=$1
elif [ $# -gt 1 ]; then
  echo 'Usage: lorem [num]'
  exit $E_BADARGS
fi

# Print the Lorem Ipsum thingie :)

for ((i = 0; i < $_num; i++)); do
  if [ $i -gt 0 ]; then
    echo ''
  fi

  echo "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do
eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim
veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo
consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse
cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat
non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." | tr '\n' ' '
  echo ''
done
