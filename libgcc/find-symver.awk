# Extract the version of a single symbol from the version map.

/^[A-Z]/ {
  version = $1;
  next;
}

$1 == symbol {
  print version
  exit
}
