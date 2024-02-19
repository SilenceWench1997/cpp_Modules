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


#output=$(./PmergeMe $(shuf -i 1-100000 -n $uas | tr '\n' ' '))
total_sumF=0.0
total_sumS=0.0
lowestF=9999.0
lowestS=9999.0

width=12

echo " ───────────────────────────────────────────────────────"
echo "│  №  │  SortTimeVector  │   SortTimeDeque  │ IsSorted  │"
echo "│───────────────────────────────────────────────────────│"
for ((i = 1; i <= ttl; i++)); do
	output=$(./PmergeMe $(jot -r $uas 1 100000 | tr '\n' ' '))
	time_valueV=$(echo "$output" | awk '/Time to process a range of '"$uas"' elements with std::vector : / {print $(NF - 1)}')
	time_valueD=$(echo "$output" | awk '/Time to process a range of '"$uas"' elements with std::deque : / {print $(NF - 1)}')
	
	isSorted=$( echo "$output" | ./Checker)
	if (( $(echo "$lowestF > $time_valueV" | bc -l) )); then
		lowestF=$time_valueV
	fi

	if (( $(echo "$lowestS > $time_valueD" | bc -l) )); then
		lowestS=$time_valueD
	fi

	unit=$(echo "$output" | awk '/Time to process a range of '"$uas"' elements with std::vector/ {print $(NF)}')
	spaces=$(( ($width - ${#i}) / 2))
	printf "│%5d" $i
	echo "│ $time_valueV $unit │ $time_valueD $unit │    $isSorted    │"
	total_sumF=$(echo "$total_sumF + $time_valueV" | bc)
	total_sumS=$(echo "$total_sumS + $time_valueD" | bc)
done

middleSpeedF=$(awk "BEGIN { printf \"%.6f\", $total_sumF / $ttl }")
middleSpeedS=$(awk "BEGIN { printf \"%.6f\", $total_sumS / $ttl }")

echo " ─────────────────────────────────────────────────────── "
echo " Average time to sort using std::vector: $middleSpeedF $unit"
echo " Quickest sorting done using std::vector: $lowestF $unit"
echo " Average time to sort using std::deque: $middleSpeedS $unit"
echo " Quickest sorting done using std::deque: $lowestS $unit"
