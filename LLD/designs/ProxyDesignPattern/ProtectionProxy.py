class INetFlixService:
    def watch_movie(self, movie):
        pass

    def watchTrailer(self, movie):
        pass


class NetflixService(INetFlixService):
    def watch_movie(self, movie):
        print(f"Watching movie: {movie}")

    def watchTrailer(self, movie):
        print(f"Watching trailer for: {movie}")


class User:
    def __init__(self, name, is_premium):
        self._name = name
        self._is_premium = is_premium

    def isPremiumUser(self):
        return self._is_premium

    @property
    def Name(self):
        return self._name


class NetflixProxy(INetFlixService):
    def __init__(self, user):
        self._user = user
        self._netflix_service = NetflixService()

    def watch_movie(self, movie):
        if self._user.isPremiumUser():
            self._netflix_service.watch_movie(movie)
        else:
            print("Only premium users can watch movies.")
            self._netflix_service.watchTrailer(movie)

    def watchTrailer(self, movie):
        self._netflix_service.watchTrailer(movie)


class Client:
    def __init__(self, netflix_service):
        self._netflix_service = netflix_service

    def WatchMovie(self, movie):
        self._netflix_service.watch_movie(movie)


def main():
    user = User("John", False)
    proxy = NetflixProxy(user)
    client = Client(proxy)
    user2 = User("Jane", True)
    proxy2 = NetflixProxy(user2)
    client2 = Client(proxy2)
    # client.WatchMovie("Inception")
    client2.WatchMovie("Interstellar")


if __name__ == "__main__":
    main()
