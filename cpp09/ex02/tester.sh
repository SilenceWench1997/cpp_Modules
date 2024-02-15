if [ "$#" -ne 2 ]; then
	echo "Usage: $0 <times_to_launch> <unsorted_array_size>"
	exit 1
fi

ttl="$1"
uas="$2"

if ! [[ "$ttl" =~ ^[1-9][0-9]*$ ]]; then
	echo "Error: Arguments must be positive integers."
	exit 1
fi

if ! [[ "$uas" =~ ^[1-9][0-9]*$ ]]; then
	echo "Error: Arguments must be positive integers."
	exit 1
fi


total_sum=0.0

for ((i = 1; i <= ttl; i++)); do
	echo "\nLaunching PmergeMe $i"
	output=$(./PmergeMe $(jot -r $uas 1 100000 | tr '\n' ' '))
	time_valueV=$(echo "$output" | awk '/Time to process a range of '"$uas"' elements with std::vector : / {print $(NF - 1)}')
	unit=$(echo "$output" | awk '/Time to process a range of '"$uas"' elements with std::vector/ {print $(NF)}')
	echo "$time_valueV $unit"
	total_sum=$(echo "$total_sum + $time_valueV" | bc)
done

middleSpeed=$(awk "BEGIN { print $total_sum / $ttl }")

echo "Done! $middleSpeed"


#add variables for containers.
