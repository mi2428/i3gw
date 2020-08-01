# Maintainer: Taichi MIYA <tmiya@protonmail.ch>
pkgname=i3gw-git
pkgver=VERSION
pkgrel=1
pkgdesc="i3 ghost window - invoking transparent window using GTK3"
arch=('i686', 'x86_64')
url="https://github.com/mi2428/i3gw"
license=('MIT')
groups=()
depends=('gtk3')
makedepends=('git')
provides=("${pkgname%-VCS}")
conflicts=("${pkgname%-VCS}")
replaces=()
backup=()
options=()
install=
source=('git+https://github.com/mi2428/i3gw.git')
noextract=()
md5sums=('SKIP')

pkgver() {
	cd "$srcdir/${pkgname}"
	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$srcdir/${pkgname}"
	./configure --prefix=/usr
	make
}

package() {
	cd "$srcdir/${pkgname}"
    make install
}
