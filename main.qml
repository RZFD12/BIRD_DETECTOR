import QtQuick 2.15
import QtPositioning 5.15
import QtLocation 5.15

Item {
    id: item
    ListModel {
        id: mymodel
    }
    Map {
        id: map
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"
        }
        center: QtPositioning.coordinate(56.3287, 44.002)
        zoomLevel: 6
        activeMapType: supportedMapTypes[3]
        MapItemView {
            z: polygon.z + 1
            model: mymodel
            delegate: MapCircle {
                radius: 100000
                opacity: 0.5
                border.width: 3
                color: 'green'
                center: QtPositioning.coordinate(model.coords.latitude,
                                                 model.coords.longitude)
            }
        }
        MapPolygon {
            id: polygon
            border.width: 0
        }
    }
    function moveMarker(index, baseLat, baseLon) {
        var coord = QtPositioning.coordinate(baseLat, baseLon)
        mymodel.set(index, {
                        "coords": coord
                    })
        var path = polygon.path
        path[index] = coord
        polygon.path = path
    }
    function addMarker(baseLat, baseLon) {
        var coord = QtPositioning.coordinate(baseLat, baseLon)
        mymodel.append({
                           "coords": coord
                       })
        polygon.addCoordinate(coord)
    }
    function delMarkers() {
        mymodel.clear()
        //polygon.removeCoordinate(coordinate)
    }
}
