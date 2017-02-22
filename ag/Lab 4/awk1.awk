$3~/^economica/ && $4~/^Sun/{
	if (!a[$1]++)
		print $1
}
