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

	if { grep -oqe "${featname}" "${out_file}" >/dev/null 2>/dev/null; }; then
		echo "feature already enabled at user level"
		exit 0
	fi

	if ! [ -f "${out_file}" ]; then
		cp -n "${og_file}" "${out_file}"
	fi

	if grep -oqEe '^Exec ?=.+--enable-features=' "${out_file}" >/dev/null; then
		SED_EXPR="\:^Exec ?=:s:(--enable-features=[^ ]+):\\1\,${featname}:"
	else
		SED_EXPR="\:^Exec ?=:s:(( %U)?$): --enable-features=${featname}\\1:"
	fi

	sed -i.bak -E -e "${SED_EXPR}" "${out_file}"
	echo updated with history navigation gesture! 🎆

}
