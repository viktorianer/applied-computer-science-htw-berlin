/**
 * Repraesentiert einen Genre eines Musikmediums.
 *
 * @author Viktor Schmidt, s0529652
 * @version 1.0
 */
public enum Genre {
    ROCK(1, "Rock"),
    POP(2, "Pop"),
    KLASSIK(3, "Klassik"),
    HIPHOP(4, "HipHop"),
    METAL(5, "Metal"),
    TECHNO(6, "Techno"),
    JAZZ(7, "Jazz");
    /**
     * Die Kennziffer des Genre
     */
    private int id;
    /**
     * Die Bezeichnung des Genres
     */
    private String genre;

    /**
     * Erzeugt Objekte des Typs Genre.
     *
     * @param dieID    Die ID des Genres.
     * @param dasGenre Die Bezeichnung des Genres.
     */
    Genre(int dieID, String dasGenre) {
        id = dieID;
        genre = dasGenre;
    }
}
