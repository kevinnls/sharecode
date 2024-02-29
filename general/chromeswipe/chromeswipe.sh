#!/bin/sh
#
set -e
{

	fname=google-chrome.desktop
	[ -n "${1}" ] && case ${1} in
		stable)
			fname=google-chrome.desktop
			;;
		unstable)
			fname=google-chrome-unstable.desktop
			;;
		*)
			>&2 echo what variant of Google Chrome is \"$1\"? Dunno. Bye.
			exit 5
			;;
	esac

	og_file="/usr/share/applications/${fname}"
	out_dir="${HOME}/.local/share/applications"
	out_file="${out_dir}/${fname}"

	featname=TouchpadOverscrollHistoryNavigation

	if ! [ -d "${out_dir}" ]; then
		mkdir -p "${out_dir}"
	fi

	if grep -oqe "${featname}" "${og_file}" >/dev/null; then
		echo "feature already enabled at system level"
		exit 0
	fi

	if grep -oqe "${featname}" "${out_file}" >/dev/null; then
		echo "feature already enabled at user level"
		exit 0
	fi

	if ! [ -f "${out_file}" ]; then
		cp -n "${og_file}" "${out_file}"
	fi

	if grep -oqe '--enable-features' "${outfile}" >/dev/null; then
		sed -E "s:(--enable-features=[^\s]+):\1,TouchpadOverscrollHistoryNavigation:" \
			"${og_file}" >${out_file}
		echo "added feature to existing destkop file"
	else
		sed "s:/usr/bin/google-chrome-stable:/usr/bin/google-chrome-stable --enable-features=${featname}:" \
			"${og_file}" >${out_file}
		echo "created destkop file with feature"
	fi

}
